/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_x.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sremenyi <sremenyi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:33:50 by sremenyi          #+#    #+#             */
/*   Updated: 2021/03/04 17:03:08 by sremenyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_x(t_buffer *b, t_flags *f, unsigned int c, char *str)
{
	char type;

	type = *str;
	f->b_num_zero = (c == 0) ? 1 : 0;
	f->to_write = ft_puthexa_len(b, f, c);
	str = conversion_helper(b, f, str, type);
	while (f->zeros-- > 0)
		add_buff(b, f, '0');
	if (f->b_preci == 2 && f->precision == 0 && c == 0)
		(f->width != 0) ? (b->buffer[b->buff_i] = ' ') :
			(b->buffer[b->buff_i] = '\0');
	else
		ft_puthexa(b, f, c, &type);
	if (f->b_left_aligned)
		while (f->width > 0)
			add_buff(b, f, ' ');
	return (str);
}
