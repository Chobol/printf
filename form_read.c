/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sremenyi <sremenyi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 18:26:17 by sremenyi          #+#    #+#             */
/*   Updated: 2021/03/04 20:14:02 by sremenyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_type(char c)
{
	if (c == '%' || c == 'c' || c == 's' || c == 'p' || c == 'd'
			|| c == 'i' || c == 'u' || c == 'x' || c == 'X')
		return (1);
	return (0);
}

void	r_flags(t_buffer *b, t_flags *f, char *str, int *i)
{
	while (str[*i] == '0' || str[*i] == '*' || str[*i] == '-')
	{
		if (str[*i] == '*')
		{
			f->breadth = va_arg(b->args, int);
			(*i)++;
			if (f->breadth < 0)
			{
				f->breadth *= -1;
				f->b_left_aligned = 1;
			}
		}
		if (str[*i] == '0')
		{
			f->b_filling_zero = 1;
			(*i)++;
		}
		else if (str[*i] == '-')
		{
			f->b_left_aligned = 1;
			(*i)++;
		}
	}
}

void	w_precision(t_buffer *b, t_flags *f, char *str, int *i)
{
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		f->breadth = f->breadth * 10 + str[*i] - '0';
		(*i)++;
	}
	if (str[*i] == '.')
	{
		(*i)++;
		if (str[*i] == '*')
		{
			f->b_precision = 1;
			f->precision = va_arg(b->args, int);
			(*i)++;
		}
		if (((ft_type(str[*i]) || str[*i] == '0') && f->b_precision == 0)
				|| (ft_type(str[*i]) || str[*i] == '0'))
			f->b_precision = 2;
		else
			f->b_precision = 1;
		while (str[*i] >= '0' && str[*i] <= '9')
		{
			f->precision = f->precision * 10 + str[*i] - '0';
			(*i)++;
		}
	}
}

char	*ft_placeholder(t_buffer *b, t_flags *f, char *str)
{
	int	i;

	i = 0;
	r_flags(b, f, str, &i);
	w_precision(b, f, str, &i);
	if (ft_type(*(str + i)))
		return (str + i);
	else
		return (str - 1);
}

char	*r_format(t_buffer *b, t_flags *f, char *str)
{
	str++;
	str = ft_placeholder(b, f, str);
	if (*str == '%' || *str == 'c')
		str = ft_c(b, f, *str == 'c' ? va_arg(b->args, int) : '%', str) + 1;
	else if (*str == 's')
		str = ft_s(b, f, va_arg(b->args, char *), str) + 1;
	else if (*str == 'd' || *str == 'i')
		str = ft_d_i(b, f, va_arg(b->args, int), str) + 1;
	else if (*str == 'u')
		str = ft_u(b, f, va_arg(b->args, unsigned int), str) + 1;
	else if (*str == 'x' || *str == 'X')
		str = ft_x(b, f, va_arg(b->args, unsigned int), str) + 1;
	else if (*str == 'p')
		str = ft_p(b, f, va_arg(b->args, unsigned long int), str) + 1;
	return (str);
}
