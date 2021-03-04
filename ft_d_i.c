/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_d_i.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sremenyi <sremenyi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:31:09 by sremenyi          #+#    #+#             */
/*   Updated: 2021/03/04 20:06:25 by sremenyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

char	*ft_d_i_2(t_buffer *b, t_flags *f, int num, char *str)
{
	if (num < 0 && f->b_filling_zero == 0)
		add_buffer(b, f, '-');
	while (f->zeros-- > 0)
	{
		if (f->minus == 1 && f->b_filling_zero == 1 && f->b_just_one == 0)
		{
			add_buffer(b, f, '-');
			f->b_just_one = 1;
		}
		add_buffer(b, f, '0');
	}
	if (f->b_precision == 2 && f->precision == 0 && num == 0)
		(f->breadth != 0) ? (b->buffer[b->buff_i] = ' ') :
			(b->buffer[b->buff_i] = '\0');
	else
	{
		if (f->minus == 1 && f->b_filling_zero == 1 && f->b_just_one == 0)
			add_buffer(b, f, '-');
		ft_putnbr(b, f, num);
	}
	if (f->b_left_aligned)
		while (f->breadth > 0)
			add_buffer(b, f, ' ');
	return (str);
}

char	*ft_d_i(t_buffer *b, t_flags *f, int num, char *str)
{
	f->minus = (num < 0) ? 1 : 0;
	f->b_num_zero = (num == 0) ? 1 : 0;
	f->to_write = ft_number_len(b, f, num) + f->minus;
	if (f->b_left_aligned == 1 && f->b_filling_zero == 1)
		f->b_filling_zero = 0;
	if ((f->b_precision == 1 || f->b_precision == 2) && f->precision >= f->to_write)
		f->zeros = f->precision - f->to_write + f->minus;
	else if (f->b_precision == 2 && f->precision == 0 && num == 0)
		f->to_write = 0;
	if (!f->b_left_aligned)
		f->breadth = f->breadth - f->to_write - f->zeros;
	if (f->b_filling_zero == 1 && !f->b_left_aligned && f->b_precision == 0)
	{
		if (f->minus == 1 && f->b_filling_zero == 1 && f->b_just_one == 0)
		{
			b->buffer[b->buff_i++] = '-';
			f->b_just_one = 1;
		}
		while (f->breadth > 0)
			add_buffer(b, f, '0');
	}
	else if (!f->b_left_aligned)
		while (f->breadth > 0)
			add_buffer(b, f, ' ');
	return (ft_d_i_2(b, f, num, str));
}
