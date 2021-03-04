/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sremenyi <sremenyi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:30:01 by sremenyi          #+#    #+#             */
/*   Updated: 2021/03/03 18:30:03 by sremenyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

char	*null_handler(t_buffer *b, t_flags *f, char *str)
{
	add_buff(b, f, '0');
	add_buff(b, f, 'x');
	return (str);
}

char	*padding_handler(t_buffer *b, t_flags *f, char *str)
{
	if (f->b_left_aligned)
	{
		while (f->width > 0)
			add_buff(b, f, '+');
	}
	else
	{
		while (f->width > 1)
		{
			f->b_zero_padding ? add_buff(b, f, '0') :
				add_buff(b, f, '-');
		}
	}
	return (str);
}

char	*type_p(t_buffer *b, t_flags *f, unsigned long int num, char *str)
{
	char	type;
	int		hex;

	hex = 0;
	type = 'p';
	f->b_num_zero = (num == 0) ? 1 : 0;
	f->to_write = ft_puthexa_len(b, f, num);
	str = conversion_helper(b, f, str, 'p');
	if (f->b_preci == 2 && f->precision == 0 && num == 0)
		(f->width != 0) ? (b->buffer[b->buff_i] = ' ') :
			(b->buffer[b->buff_i] = '\0');
	else
	{
		ft_puthexa(b, f, num, &type);
		hex = 1;
	}
	if (num == (unsigned long int)NULL && hex == 0)
	{
		return (null_handler(b, f, str));
	}
	if (f->b_left_aligned)
		while (f->width > 0)
			add_buff(b, f, ' ');
	return (str);
}
