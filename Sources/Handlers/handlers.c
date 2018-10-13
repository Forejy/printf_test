#include "../../Includes/Auxiliary_Functions/strings_functions.h"
#include "../../Includes/Print_Unicode/print_unicode.h"
#include "../../Includes/Handlers/handle_colors.h"
#include "../../Includes/Handlers/test_conv_champs_prec.h"

static int			define_lenght_conv(const char *length, t_flag *flag)
{
	int lenght_conv;

	lenght_conv = 0;
	if (*length == 'l')
	{
		if (*(length + 1) == 'l')
			lenght_conv = LL;
		else
			lenght_conv = L;
	}
	else if (*length == 'h')
	{
		if (*(length + 1) == 'h')
			lenght_conv = HH;
		else
			lenght_conv = H;
	}
	else if (*length == 'j')
		lenght_conv = J;
	else if (*length == 'z')
		lenght_conv = Z;
	if (lenght_conv > flag->lenght_conv)
		flag->lenght_conv = lenght_conv;
	return (lenght_conv % 3);
}

void			initialize_t_flag(t_flag	*flag)
{
	flag->more = 0;
	flag->less = 0;
	flag->zero = 0;
	flag->hash = 0;
	flag->blank = 0;
	flag->champs = 0;
	flag->precision = -1;
	flag->pointer = 0;
	flag->hexa = 0;
	flag->binary = 0;
	flag->octal = 0;
	flag->character_or_string = 0;
	flag->unicode_c = 0;
	flag->unicode_s = 0;
	flag->conv_d = 0;
	flag->conv_f = 0;
	flag->conv_f_intpart = 0;
	flag->lenght_conv = 0;
}

int			analyze_and_printf(const char *format, va_list *ap, t_flag *flag)
{
	short i;
	short j;
	int   ret;

	i        = 0;
	j        = -1;
	if (*format == '\0' && (write(1, flag->buffer, flag->len_buffer) >= 0))
		return (0);
	initialize_t_flag(flag);
	while (i > j)
	{
		j = i;
		i += test_flag(format[i], flag);
		i += define_lenght_conv(&format[i], flag);
		i += test_champs(&format[i], flag, ap);
		if (format[i] == '.')
			i += test_precision(&format[i], flag, ap);
	}
	if ((ret = test_if_conv(format[i], flag, i)) != -2)
		return (ret);
	else if ((ret = handle_conversions(format[i], ap, *flag)) == -1)
		return (-1);
	else
		flag->lenght_print += ret;
	return (i + 1);
}

short			initialize_handle_format(int *i, unsigned short *j, int *ret, t_flag *flag)
{
	*i = 0;
	*ret = 0;
	flag->lenght_print = 0;
	flag->len_buffer = 0;
	flag->color = 0;
	*j = 0;
	return (1);
}

int			handle_format(const char *format, va_list *ap)
{
	int				i;
	int				ret;
	t_flag			flag;
	unsigned short	j;

	if (((initialize_handle_format(&i, &j, &ret, &flag))) && format != NULL)
	{
		while (format[i] != '\0')
		{
			if (ret >= 0 && format[i] == '%')
			{
				flag.len_buffer = j;
				if ((ret = analyze_and_printf(&format[i + 1], ap, &flag)) > -1)
					i = i + ret + 1;
				if ((j = 0) || ret == -1)
					return (-1);
            }
			else if ((ret = pre_handle_colors(&format[i], &flag, &j)) > 0)
				i += ret;
			else if ((flag.buffer[j++] = format[i++]))
				flag.lenght_print++;
		}
	}
	write(1, flag.buffer, j);
	return(flag.lenght_print);
}