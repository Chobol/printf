/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sremenyi <sremenyi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:31:09 by sremenyi          #+#    #+#             */
/*   Updated: 2021/03/03 18:31:50 by sremenyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

char	*type_di2(t_buffer *b, t_flags *f, int num, char *str)
{
	if (num < 0 && f->b_zero_padding == 0)
		add_buff(b, f, '-');
	while (f->zeros-- > 0)
	{
		if (f->negative == 1 && f->b_zero_padding == 1 && f->b_only_once == 0)
		{
			add_buff(b, f, '-');
			f->b_only_once = 1;
		}
		add_buff(b, f, '0');
	}
	if (f->b_preci == 2 && f->precision == 0 && num == 0)
		(f->width != 0) ? (b->buffer[b->buff_i] = ' ') :
			(b->buffer[b->buff_i] = '\0');
	else
	{
		if (f->negative == 1 && f->b_zero_padding == 1 && f->b_only_once == 0)
			add_buff(b, f, '-');
		ft_putnbr(b, f, num);
	}
	if (f->b_left_aligned)
		while (f->width > 0)
			add_buff(b, f, ' ');
	return (str);
}

char	*type_di1(t_buffer *b, t_flags *f, int num, char *str)
{
	f->negative = (num < 0) ? 1 : 0;
	f->b_num_zero = (num == 0) ? 1 : 0;
	f->to_write = ft_putnbr_len(b, f, num) + f->negative;
	if (f->b_left_aligned == 1 && f->b_zero_padding == 1)
		f->b_zero_padding = 0;
	if ((f->b_preci == 1 || f->b_preci == 2) && f->precision >= f->to_write)
		f->zeros = f->precision - f->to_write + f->negative;
	else if (f->b_preci == 2 && f->precision == 0 && num == 0)
		f->to_write = 0;
	if (!f->b_left_aligned)
		f->width = f->width - f->to_write - f->zeros;
	if (f->b_zero_padding == 1 && !f->b_left_aligned && f->b_preci == 0)
	{
		if (f->negative == 1 && f->b_zero_padding == 1 && f->b_only_once == 0)
		{
			b->buffer[b->buff_i++] = '-';
			f->b_only_once = 1;
		}
		while (f->width > 0)
			add_buff(b, f, '0');
	}
	else if (!f->b_left_aligned)
		while (f->width > 0)
			add_buff(b, f, ' ');
	return (type_di2(b, f, num, str));
}
