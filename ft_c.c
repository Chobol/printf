/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sremenyi <sremenyi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:28:19 by sremenyi          #+#    #+#             */
/*   Updated: 2021/03/04 20:06:25 by sremenyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

char	*ft_c(t_buffer *b, t_flags *f, int c, char *str)
{
	if (f->b_left_aligned)
	{
		add_buffer(b, f, c);
		while (f->breadth > 0)
			add_buffer(b, f, ' ');
	}
	else
	{
		while (f->breadth > 1)
		{
			f->b_filling_zero ? add_buffer(b, f, '0') :
				add_buffer(b, f, ' ');
		}
		add_buffer(b, f, c);
	}
	return (str);
}
