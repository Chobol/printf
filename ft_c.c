/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sremenyi <sremenyi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:28:19 by sremenyi          #+#    #+#             */
/*   Updated: 2021/03/04 16:54:15 by sremenyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char	*type_c(t_buffer *b, t_flags *f, int c, char *str)
{
	if (f->b_left_aligned)
	{
		add_buff(b, f, c);
		while (f->width > 0)
			add_buff(b, f, ' ');
	}
	else
	{
		while (f->width > 1)
		{
			f->b_zero_padding ? add_buff(b, f, '0') :
				add_buff(b, f, ' ');
		}
		add_buff(b, f, c);
	}
	return (str);
}
