#include "../../Includes/Handlers/handle_conversions_2.h"
#include "../../Includes/Auxiliary_Functions/strings_functions.h"
#include "../../Includes/Print_Unicode/print_unicode.h"
#include "../../Includes/Auxiliary_Functions/numbers_functions.h"
#include "../../Includes/Auxiliary_Functions/bonus.h"
#include "../../Includes/Auxiliary_Functions/print_pointer_address.h"

int		handle_conversions_5(char conv, va_list *ap, t_flag flag, int lenght_conv)
{
	if (conv == 'x')
	{
		if (lenght_conv == H)
			return (my_putnbr_hexa((unsigned short) (va_arg(*ap, int)), flag));
		else if (lenght_conv == HH)
			return(my_putnbr_hexa((unsigned char) (va_arg(*ap, int)), flag));
		else if (lenght_conv == L)
			return(my_putnbr_hexa(va_arg(*ap, unsigned long), flag));
		else if (lenght_conv == LL)
			return(my_putnbr_hexa(va_arg(*ap, unsigned long long), flag));
		else if (lenght_conv == J)
			return(my_putnbr_hexa(va_arg(*ap, uintmax_t), flag));
		else if (lenght_conv == Z)
			return(my_putnbr_hexa(va_arg(*ap, unsigned long), flag));
		else
			return(my_putnbr_hexa(va_arg(*ap, unsigned int), flag));
	}
	else if (conv == '%')
		return(my_putchar_printf('%', flag));
	else if (conv == 'C' || (conv == 'c' && lenght_conv == L))
		return(my_put_wint_t(va_arg(*ap, wint_t), flag));
	else if (conv == 'O')
		return(my_put_octal(va_arg(*ap, unsigned long), flag));
	else
		return(handle_conversions_6(conv, ap, flag, lenght_conv));
}

int		handle_conversions_4(char conv, va_list *ap, t_flag flag,int lenght_conv)
{
	int total_len;

	if (conv == 'u')
	{
		if (lenght_conv == H)
			total_len = my_put_unsigned_long_long((unsigned short) (va_arg(*ap, int)), flag);
		else if (lenght_conv == HH)
			total_len = my_put_unsigned_long_long((unsigned char) (va_arg(*ap, int)), flag);
		else if (lenght_conv == L)
			total_len = my_put_unsigned_long_long(va_arg(*ap, unsigned long), flag);
		else if (lenght_conv == LL)
			total_len = my_put_unsigned_long_long(va_arg(*ap, unsigned long long), flag);
		else if (lenght_conv == J)
			total_len = my_put_unsigned_long_long(va_arg(*ap, uintmax_t), flag);
		else if (lenght_conv == Z)
			total_len = my_put_unsigned_long_long(va_arg(*ap, size_t), flag);
		else
			total_len = my_put_unsigned_long_long(va_arg(*ap, unsigned int), flag);
	}
	else if (conv == 'O' && lenght_conv == L)
		total_len = my_put_octal(va_arg(*ap, unsigned long long), flag);
	else
		total_len = handle_conversions_5(conv, ap, flag, lenght_conv);
	return (total_len);
}

int			handle_conversions_3(char conv, va_list *ap, t_flag flag,int lenght_conv)
{
	int total_len;

	if (conv == 'D')
	{
		if (lenght_conv == L)
			total_len = my_putnbr_long_long(va_arg(*ap, long long), flag);
		else if (lenght_conv == H)
			total_len = my_putnbr_long_long(va_arg(*ap, long long), flag);
		else
			total_len = my_putnbr_long_long(va_arg(*ap, long), flag);
	}
	else if (conv == 'U')
	{
		if (lenght_conv == L)
			total_len = my_put_unsigned_long_long(va_arg(*ap, unsigned long long), flag);
		else if (lenght_conv == H)
			total_len = my_put_unsigned_long_long(va_arg(*ap, unsigned long long), flag);
		else
			total_len = my_put_unsigned_long_long(va_arg(*ap, unsigned long), flag);
	}
	else if (conv == 'n')
		assigns_to_n(ap, lenght_conv, flag);
	else
		total_len = handle_conversions_4(conv, ap, flag, lenght_conv);
	return (total_len);
}

int		handle_conversions_2(char conv, va_list *ap, t_flag flag,int lenght_conv)
{
	int total_len;

	if (conv == 'd' || conv == 'i')
	{
		if (lenght_conv == H)
			total_len = my_putnbr_long_long((short) (va_arg(*ap, int)), flag);
		else if (lenght_conv == HH)
			total_len = my_putnbr_long_long((char) (va_arg(*ap, int)), flag);
		else if (lenght_conv == L)
			total_len = my_putnbr_long_long(va_arg(*ap, long), flag);
		else if (lenght_conv == LL)
			total_len = my_putnbr_long_long(va_arg(*ap, long long), flag);
		else if (lenght_conv == J)
			total_len = my_putnbr_long_long(va_arg(*ap, intmax_t), flag);
		else if (lenght_conv == Z)
			total_len = my_putnbr_long_long(va_arg(*ap, ssize_t), flag);
		else
			total_len = my_putnbr_long_long(va_arg(*ap, int), flag);
	}
	else if (conv == 'p')
		total_len = my_putaddress(va_arg(*ap, uintmax_t), flag);
	else 
		total_len = handle_conversions_3(conv, ap, flag, lenght_conv);
	return (total_len);
}

int			handle_conversions(char conv, va_list *ap, t_flag flag)
{
	int  total_len;

	if (conv == 'o')
	{
		if (flag.lenght_conv == H)
			total_len = my_put_octal((unsigned short)(va_arg(*ap,  unsigned int)), flag);
		else if (flag.lenght_conv == HH)
			total_len = my_put_octal((unsigned char)(va_arg(*ap,  unsigned int)), flag);
		else if (flag.lenght_conv == L)
			total_len = my_put_octal(va_arg(*ap, unsigned long), flag);
		else if (flag.lenght_conv == LL)
			total_len = my_put_octal(va_arg(*ap, unsigned long long), flag);
		else if (flag.lenght_conv == J)
			total_len = my_put_octal(va_arg(*ap, uintmax_t), flag);
		else if (flag.lenght_conv == Z)
			total_len = my_put_octal(va_arg(*ap, unsigned long), flag);
		else
			total_len = my_put_octal(va_arg(*ap, unsigned int), flag);
	}
	else if (conv == 'S' || (conv == 's' && flag.lenght_conv == L))
		total_len = my_put_wchar_t(va_arg(*ap, wchar_t *), flag);
	else
		total_len = handle_conversions_2(conv, ap, flag, flag.lenght_conv);
	return (total_len);
}









