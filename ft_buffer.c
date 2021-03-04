/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sremenyi <sremenyi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:41:36 by sremenyi          #+#    #+#             */
/*   Updated: 2021/03/03 18:08:48 by sremenyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_clear(t_buffer *b)
{
	b->written += b->buff_i;
	write(1, b->buffer, BUFFER_SIZE);
	ft_bzero(b->buffer, sizeof(b->buffer));
	b->buff_i = 0;
}

void	add_buff(t_buffer *b, t_flags *f, char c)
{
	if (b->buff_i == BUFFER_SIZE)
		write_clear(b);
	b->buffer[b->buff_i] = c;
	b->buff_i++;
	f->width--;
}
