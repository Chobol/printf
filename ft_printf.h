/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sremenyi <sremenyi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/03 15:43:09 by sremenyi          #+#    #+#             */
/*   Updated: 2021/03/04 20:14:02 by sremenyi         ###   ########.fr       */
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
	int			breadth;
	int			precision;
	int			b_precision;
	int			b_left_aligned;
	int			b_filling_zero;
	int			b_just_one;
	int			b_num_zero;
	int			to_write;
	int			num_len;
	int			zeros;
	int			minus;
}				t_flags;

int				ft_printf(const char *s, ...);

char			*ft_c(t_buffer *b, t_flags *f, int c, char *str);
char			*ft_s(t_buffer *b, t_flags *f, char *print, char *str);
char			*ft_s_left(t_buffer *b, t_flags *f, char *print, char *str);
char			*ft_d_i(t_buffer *b, t_flags *f, int num, char *str);
char			*ft_d_i_2(t_buffer *b, t_flags *f, int num, char *str);
char			*ft_u(t_buffer *b, t_flags *f, unsigned int num, char *str);
char			*ft_p(t_buffer *b, t_flags *f, unsigned long int num,
						char *str);
char			*ft_x(t_buffer *b, t_flags *f, unsigned int c,
						char *str);

int				ft_number_len(t_buffer *b, t_flags *f, long n);
int				ft_hexa_len(t_buffer *b, t_flags *f, unsigned long x);
void			ft_putnbr(t_buffer *b, t_flags *f, long n);
void			ft_hexa(t_buffer *b, t_flags *f, unsigned long x,
							char *type);

int				ft_type(char c);
void			r_flags(t_buffer *b, t_flags *f, char *str, int *i);
void			w_precision(t_buffer *b, t_flags *f, char *str, int *i);
char			*r_format(t_buffer *b, t_flags *f, char *str);
char			*ft_placeholder(t_buffer *b, t_flags *f, char *str);

void			write_clear(t_buffer *b);
void			add_buffer(t_buffer *b, t_flags *f, char c);

void			ft_bzero(void *s, size_t n);
size_t			ft_strlen(const char *s);
char			*conversion(t_buffer *b, t_flags *f, char *str,
									char type);
#endif
