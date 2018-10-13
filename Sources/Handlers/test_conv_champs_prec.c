#include "../../Includes/Handlers/handlers.h"
#include "../../Includes/Auxiliary_Functions/strings_functions.h"

int			test_flag(char format_flag, t_flag	*flag)
{
	if (format_flag == '+')
	{
		flag->more = 1;
		return (1);
	}
	if (format_flag == '-')
	{
		flag->less = 1;
		return (1);
	}
	if (format_flag == '0')
	{
		flag->zero = 1;
		return (1);
	}
	if (format_flag == '#')
	{
		flag->hash = 2;
		return (1);
	}
	if (format_flag == ' ' && (flag->blank = 1))
		return (1);
	else
		return (0);
}

short			test_champs_star(const char *format, t_flag *flag, va_list *ap)
{
	int		temp_star;

	if (format[0] == '*')
	{
		temp_star = va_arg(*ap, int);
		if (temp_star < 0)
		{
			flag->less = 1;
			temp_star *= -1;
		}
		flag->champs = temp_star;
		return (1);
	}
	return (0);
}

int			test_champs(const char *format, t_flag *flag, va_list *ap)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	if (test_champs_star(format, flag, ap))
		return (1);
	if (format[0] == '0')
	{
		while (format[i] == '0')
			i++;
		if (format[i] != '.')
			return (i - 1);
		else
			return (i);
	}
	while (format[i] >= '0' && format[i] <= '9')
		nb = nb * 10 + (format[i++] - '0');
	if (nb > 0)
		flag->champs = nb;
	if (i > 0)
		return (i);
	return (0);
}

int				test_precision(const char *format, t_flag *flag, va_list *ap)
{
	int		i;
	int		nb;
	int		temp_star;

	i = 0;
	nb = 0;
	if (format[0] == '.')
	{
		i++;
		while (format[i] >= '0' && format[i] <= '9')
			nb = nb * 10 + (format[i++] - '0');
		if (format[i] == '*')
		{
			temp_star = va_arg(*ap, int);
			if (temp_star >= 0)
				flag->precision = temp_star;
			i++;
		}
		else if (nb >= 0)
			flag->precision = nb;
	}
	return (i);
}

int		test_if_conv(char conv, t_flag *flag, short i)
{
	if (conv != 'd' && conv != 'D' && conv != 'i' && conv != 'o'
		&& conv != 'O' && conv != 'u' && conv != 'U' && conv != 'x'
		&& conv != 'X' && conv != 'c' && conv != 'C' && conv != '%'
		&& conv != 's' && conv != 'S' && conv != 'p' && conv != 'n'
		&& conv != 'b'&& conv != 'f' && conv != 'F')
	{
		if (conv >= 'a' && conv <= 'z')
			return (-1);
		else if (conv == '\0')
			return (i);
		else
		{
			flag->lenght_print += my_putchar_printf(conv, *flag);
			return (i + 1);
		}
	}
	return (-2);
}