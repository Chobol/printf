/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sremenyi <sremenyi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:42:11 by sremenyi          #+#    #+#             */
/*   Updated: 2021/03/04 19:31:41 by sremenyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *s, ...)
{
	t_buffer	b;
	t_flags		f;
	char		*str;

	str = (char *)s;
	ft_bzero(&b, sizeof(b));
	va_start(b.args, s);
	while (*str)
	{
		if (*str == '%')
		{
			ft_bzero(&f, sizeof(f));
			str = r_format(&b, &f, str);
		}
		else
			add_buffer(&b, &f, *str++);
	}
	write(1, b.buffer, b.buff_i);
	va_end(b.args);
	return (b.buff_i + b.written);
}
