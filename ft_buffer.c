/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chobol <chobol@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/28 20:56:32 by chobol            #+#    #+#             */
/*   Updated: 2021/02/28 20:59:18 by chobol           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_and_clear(t_buffer *b)
{
	b->written += b->buff_i;
	write(1, b->buffer, BUFFER_SIZE);
	ft_bzero(b->buffer, sizeof(b->buffer));
	b->buff_i = 0;
}

void	add_to_buffer(t_buffer *b, t_flags *f, char c)
{
	if (b->buff_i == BUFFER_SIZE)
		write_and_clear(b);
	b->buffer[b->buff_i] = c;
	b->buff_i++;
	f->width--;
}
