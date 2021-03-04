/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sremenyi <sremenyi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:43:09 by sremenyi          #+#    #+#             */
/*   Updated: 2021/03/04 17:02:52 by sremenyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# define BUFFER_SIZE 256

typedef struct	s_buffer
{
	va_list		args;
	char		buffer[BUFFER_SIZE];
	int			buff_i;
	int			written;
}				t_buffer;

typedef struct	s_flags
{
	int			width;
	int			precision;
	int			b_preci;
	int			b_left_aligned;
	int			b_zero_padding;
	int			b_only_once;
	int			b_num_zero;
	int			to_write;
	int			num_len;
	int			zeros;
	int			negative;
}				t_flags;

int				ft_printf(const char *s, ...);

char			*type_c(t_buffer *b, t_flags *f, int c, char *str);
char			*type_s(t_buffer *b, t_flags *f, char *print, char *str);
char			*type_s_left(t_buffer *b, t_flags *f, char *print, char *str);
char			*type_di1(t_buffer *b, t_flags *f, int num, char *str);
char			*type_di2(t_buffer *b, t_flags *f, int num, char *str);
char			*type_u(t_buffer *b, t_flags *f, unsigned int num, char *str);
char			*type_p(t_buffer *b, t_flags *f, unsigned long int num,
						char *str);
char			*ft_x(t_buffer *b, t_flags *f, unsigned int c,
						char *str);

int				ft_putnbr_len(t_buffer *b, t_flags *f, long n);
int				ft_puthexa_len(t_buffer *b, t_flags *f, unsigned long x);
void			ft_putnbr(t_buffer *b, t_flags *f, long n);
void			ft_puthexa(t_buffer *b, t_flags *f, unsigned long x,
							char *type);

int				ft_type(char c);
void			read_flags(t_buffer *b, t_flags *f, char *str, int *i);
void			width_precision(t_buffer *b, t_flags *f, char *str, int *i);
char			*read_format(t_buffer *b, t_flags *f, char *str);
char			*placeholders(t_buffer *b, t_flags *f, char *str);

void			write_clear(t_buffer *b);
void			add_buff(t_buffer *b, t_flags *f, char c);

void			ft_bzero(void *s, size_t n);
size_t			ft_strlen(const char *s);
char			*conversion_helper(t_buffer *b, t_flags *f, char *str,
									char type);
#endif
