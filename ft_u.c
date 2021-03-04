/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sremenyi <sremenyi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:33:12 by sremenyi          #+#    #+#             */
/*   Updated: 2021/03/04 20:14:10 by sremenyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_u(t_buffer *b, t_flags *f, unsigned int num, char *str)
{
	f->b_num_zero = (num == 0) ? 1 : 0;
	f->to_write = ft_number_len(b, f, num);
	str = conversion(b, f, str, 'u');
	while (f->zeros-- > 0)
		add_buffer(b, f, '0');
	if (f->b_precision == 2 && f->precision == 0 && num == 0)
		(f->breadth != 0) ? (b->buffer[b->buff_i] = ' ') :
			(b->buffer[b->buff_i] = '\0');
	else
		ft_putnbr(b, f, num);
	if (f->b_left_aligned)
		while (f->breadth > 0)
			add_buffer(b, f, ' ');
	return (str);
}
