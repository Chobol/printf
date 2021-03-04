/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sremenyi <sremenyi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:33:50 by sremenyi          #+#    #+#             */
/*   Updated: 2021/03/04 20:20:50 by sremenyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_x(t_buffer *b, t_flags *f, unsigned int c, char *str)
{
	char ch;

	ch = *str;
	f->b_num_zero = (c == 0) ? 1 : 0;
	f->to_write = ft_hexa_len(b, f, c);
	str = conversion(b, f, str, ch);
	while (f->zeros-- > 0)
		add_buffer(b, f, '0');
	if (f->b_precision == 2 && f->precision == 0 && c == 0)
		(f->breadth != 0) ? (b->buffer[b->buff_i] = ' ') :
			(b->buffer[b->buff_i] = '\0');
	else
		ft_hexa(b, f, c, &ch);
	if (f->b_left_aligned)
		while (f->breadth > 0)
			add_buffer(b, f, ' ');
	return (str);
}
