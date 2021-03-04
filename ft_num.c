/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sremenyi <sremenyi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:23:39 by sremenyi          #+#    #+#             */
/*   Updated: 2021/03/04 20:01:36 by sremenyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

void	ft_putnbr(t_buffer *b, t_flags *f, long n)
{
	if (n < 0)
		n = -n;
	if (n / 10)
		ft_putnbr(b, f, n / 10);
	add_buffer(b, f, n % 10 + '0');
}

int		ft_number_len(t_buffer *b, t_flags *f, long n)
{
	if (n < 0)
		n = -n;
	if (n / 10)
	{
		f->num_len++;
		ft_number_len(b, f, n / 10);
	}
	return (f->num_len + 1);
}

void	ft_hexa(t_buffer *b, t_flags *f, unsigned long x, char *type)
{
	if (x >= 16)
		ft_hexa(b, f, x / 16, type);
	if (*type == 'p' && f->b_just_one == 0)
	{
		add_buffer(b, f, '0');
		add_buffer(b, f, 'x');
		f->b_just_one = 1;
	}
	while (f->zeros-- > 0)
		add_buffer(b, f, '0');
	if (*type == 'x' || *type == 'p')
		add_buffer(b, f, "0123456789abcdef"[x & 15]);
	else
		add_buffer(b, f, "0123456789ABCDEF"[x & 15]);
}

int		ft_hexa_len(t_buffer *b, t_flags *f, unsigned long x)
{
	if (x >= 16)
	{
		f->num_len++;
		ft_hexa_len(b, f, x / 16);
	}
	return (f->num_len + 1);
}
