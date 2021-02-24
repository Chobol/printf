
#ifndef UTILS_H
# define UTILS_H

# include "ft_printf.h"
# include "printing.h"

# define SCIENTIFIC	(int32_t)0
# define FLOAT		(int32_t)1

void		buffer_itoa_base(t_unsigned nb, t_format format, t_buffer *buffer);
size_t		get_nb_len(uintmax_t nb, uint8_t base);
int32_t		is_denormalized(long double nb, t_format format, t_buffer *buffer);
void		padd_value(char *char_pad, int32_t padding, t_buffer *buffer);
void		print_exponent(int64_t exponent, t_unsigned print_exp,
				t_format format, t_buffer *buffer);
void		print_fraction(t_double fraction, t_format format,
				t_buffer *buffer);
void		print_itoa_base(t_unsigned nb, t_format format, char nb_str[ITOA]);
void		return_scient_parts(uint64_t *integer, long double *fraction,
				int64_t *exponent, t_double nb);

#endif
