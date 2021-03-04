/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sremenyi <sremenyi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:23:31 by sremenyi          #+#    #+#             */
/*   Updated: 2021/03/04 20:06:25 by sremenyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	int a;

	a = 0;
	while (str[a])
		a++;
	return (a);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
		*str++ = '\0';
}

char	*conversion(t_buffer *b, t_flags *f, char *str, char type)
{
	if ((f->b_precision == 1 || f->b_precision == 2) && f->precision >= f->to_write)
		f->zeros = f->precision - f->to_write;
	else if (f->b_precision == 2 && f->precision == 0 && f->b_num_zero == 1)
		f->to_write = 0;
	if (!f->b_left_aligned && type != 'p')
		f->breadth = f->breadth - f->to_write - f->zeros;
	if (!f->b_left_aligned && type == 'p')
		f->breadth = f->breadth - f->to_write - f->zeros - 2;
	if (f->b_filling_zero && !f->b_left_aligned && f->b_precision == 0)
	{
		while (f->breadth > 0)
			add_buffer(b, f, '0');
	}
	else if (!f->b_left_aligned)
		while (f->breadth > 0)
			add_buffer(b, f, ' ');
	return (str);
}
