

#include "printing.h"
#include "utils.h"

static int32_t	calculate_width(t_double nb, uint64_t dec, t_format format)
{
	if ((nb.nb < 0) || (format.flags & SIGN) || (format.flags & SPACE))
		format.width -= 1;
	format.width -= get_nb_len(dec, nb.base);
	format.width -= ft_strlen(nb.prefix);
	format.width -= (format.precision == 0) ? 0 : format.precision + 1;
	return (format.width);
}

static void		print_sign(t_double nb, t_format format, t_buffer *buffer)
{
	if (!(format.flags & RIGHT_PAD) && !(format.flags & ZERO_PAD))
		padd_value(" ", format.width - format.to_print, buffer);
	if (nb.nb < 0)
		buffered_print("-", 1, buffer);
	buffered_print(nb.prefix, ft_strlen(nb.prefix), buffer);
}


void			print_float_number(t_double nb, t_format format,
					t_buffer *buffer)
{
	uint64_t	dec;
	t_double	fraction;
	t_unsigned	nb_unsigned;

	if (is_denormalized(nb.nb, format, buffer) == SUCCESS)
		return ;
	dec = (uint64_t)ft_absld(nb.nb);
	fraction.nb = ft_absld(nb.nb) - dec;
	fraction.base = nb.base;
	format.width = calculate_width(nb, dec, format);
	print_sign(nb, format, buffer);
	if (format.precision == 0)
		nb_unsigned.nb = ft_absl(ft_round(nb.nb));
	else
		nb_unsigned.nb = dec;
	nb_unsigned.base = nb.base;
	buffer_itoa_base(nb_unsigned, format, buffer);
	if (format.flags & PREFIX || format.precision > 0)
		print_fraction(fraction, format, buffer);
	if (format.flags & RIGHT_PAD)
		padd_value(" ", format.width, buffer);
}


void			print_float_scientific(t_double nb, t_format format,
					t_buffer *buffer)
{
	uint64_t	dec;
	int64_t		exponent;
	t_unsigned	nb_unsigned;
	t_double	fraction;

	fraction.base = nb.base;
	return_scient_parts(&dec, &fraction.nb, &exponent, nb);
	if (!(format.flags & PRECISION))
		format.precision = 6;
	format.width = calculate_width(nb, dec, format);
	print_sign(nb, format, buffer);
	if (format.precision == 0)
		nb_unsigned.nb = ft_round(dec + fraction.nb);
	else
		nb_unsigned.nb = dec;
	nb_unsigned.base = nb.base;
	buffer_itoa_base(nb_unsigned, format, buffer);
	if (format.flags & PREFIX || format.precision > 0)
		print_fraction(fraction, format, buffer);
	nb_unsigned.nb = ft_absl(exponent);
	nb_unsigned.base = nb.base;
	print_exponent(exponent, nb_unsigned, format, buffer);
	if (format.flags & RIGHT_PAD)
		padd_value(" ", format.width, buffer);
}
