/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chobol <chobol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 00:03:38 by vvarodi           #+#    #+#             */
/*   Updated: 2021/03/01 17:32:48 by chobol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *s, ...)
{
	t_buffer	b;
	t_flags		f;
	char		*string;

	string = (char *)s;			//why not
	ft_bzero(&b, sizeof(b));
	va_start(b.args, s);
	while (*string)
	{
		if (*string == '%')
		{
			ft_bzero(&f, sizeof(f));
			string = read_format(&b, &f, string);
		}
		else
			add_to_buffer(&b, &f, *string++);
	}
	write(1, b.buffer, b.buff_i);
	va_end(b.args);
	return (b.buff_i + b.written);
}
