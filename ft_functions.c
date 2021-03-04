/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sremenyi <sremenyi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:23:31 by sremenyi          #+#    #+#             */
/*   Updated: 2021/03/03 18:23:33 by sremenyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n--)
		*str++ = '\0';
}

char	*conversion_helper(t_buffer *b, t_flags *f, char *str, char type)
{
	if ((f->b_preci == 1 || f->b_preci == 2) && f->precision >= f->to_write)
		f->zeros = f->precision - f->to_write;
	else if (f->b_preci == 2 && f->precision == 0 && f->b_num_zero == 1)
		f->to_write = 0;
	if (!f->b_left_aligned && type != 'p')
		f->width = f->width - f->to_write - f->zeros;
	if (!f->b_left_aligned && type == 'p')
		f->width = f->width - f->to_write - f->zeros - 2;
	if (f->b_zero_padding && !f->b_left_aligned && f->b_preci == 0)
	{
		while (f->width > 0)
			add_buff(b, f, '0');
	}
	else if (!f->b_left_aligned)
		while (f->width > 0)
			add_buff(b, f, ' ');
	return (str);
}
