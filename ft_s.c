/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sremenyi <sremenyi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:32:19 by sremenyi          #+#    #+#             */
/*   Updated: 2021/03/04 20:13:02 by sremenyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_s_left(t_buffer *b, t_flags *f, char *print, char *str)
{
	if (f->b_precision == 0)
	{
		while (*print != '\0')
			add_buffer(b, f, *print++);
	}
	else
	{
		if (f->precision < 0)
		{
			while (*print && f->precision++ < 0)
				add_buffer(b, f, *print++);
		}
		while (*print && f->precision-- > 0)
			add_buffer(b, f, *print++);
	}
	while (f->breadth > 0)
		add_buffer(b, f, ' ');
	return (str);
}

char	*ft_s(t_buffer *b, t_flags *f, char *print, char *str)
{
	int length;

	if (print == NULL)
		print = "(null)";
	length = ft_strlen(print);
	if (f->b_left_aligned == 1)
		return (ft_s_left(b, f, print, str));
	if (f->precision == 0)
	{
		f->to_write = ft_strlen(print);
		if (f->b_precision == 2)
			f->to_write = 0;
	}
	else if (f->precision < 0)
		f->to_write = length;
	else
		f->to_write = length < f->precision ? length : f->precision;
	while (f->breadth > f->to_write)
		f->b_filling_zero == 1 ? add_buffer(b, f, '0') :
			add_buffer(b, f, ' ');
	while (f->to_write-- > 0)
		add_buffer(b, f, *print++);
	return (str);
}
