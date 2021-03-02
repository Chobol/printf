/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chobol <chobol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 12:08:27 by vvarodi           #+#    #+#             */
/*   Updated: 2021/03/01 19:02:30 by chobol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char* null_handler(t_buffer *b, t_flags *f, char *str)
{
	add_to_buffer(b, f, '(');
	add_to_buffer(b, f, 'n');
	add_to_buffer(b, f, 'i');
	add_to_buffer(b, f, 'l');
	add_to_buffer(b, f, ')');
	return (str);
}


char* padding_handler(t_buffer *b, t_flags *f, char *str)
{
	if (f->b_left_aligned)
	{
		//add_to_buffer(b, f, c);
		while (f->width > 0)
			add_to_buffer(b, f, '+');
	}
	else
	{
		while (f->width > 1)
		{
			f->b_zero_padding ? add_to_buffer(b, f, '0') :
				add_to_buffer(b, f, '-');
		}
		//add_to_buffer(b, f, c);
	}
	return (str);
}


char	*type_p(t_buffer *b, t_flags *f, unsigned long int num, char *str)
{
	char type;

	if (num == (unsigned long int) NULL)
	{
		return null_handler(b, f, str);
	}
	
	type = 'p';
	f->b_num_zero = (num == 0) ? 1 : 0;
	f->to_write = ft_puthexa_len(b, f, num);
	str = conversion_helper(b, f, str, 'p');
	while (f->zeros-- > 0)
		add_to_buffer(b, f, '0');
	if (f->b_preci == 2 && f->precision == 0 && num == 0)
		(f->width != 0) ? (b->buffer[b->buff_i] = ' ') :
			(b->buffer[b->buff_i] = '\0');
	else
		ft_puthexa(b, f, num, &type);
	if (f->b_left_aligned)
		while (f->width > 0)
			add_to_buffer(b, f, ' ');
	return (str);
}
