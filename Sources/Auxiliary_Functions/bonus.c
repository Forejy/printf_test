#include "../../Includes/Handlers/handlers.h"
#include "../../Includes/Print_Final_Result/print_and_compute_final_result.h"

void		assigns_to_n(va_list *ap, int lenght_conv, t_flag flag)
{
	uintmax_t		*temp_ap;

	if (lenght_conv == H)
		temp_ap = (unsigned short*) (va_arg(*ap, int*));
	else if (lenght_conv == HH)
		temp_ap = (unsigned char*) (va_arg(*ap, int*));
	else if (lenght_conv == L)
		temp_ap = va_arg(*ap, unsigned long*);
	else if (lenght_conv == LL)
		temp_ap = (uintmax_t *) va_arg(*ap, unsigned long long*);
	else if (lenght_conv == J)
		temp_ap = va_arg(*ap, uintmax_t*);
	else if (lenght_conv == Z)
		temp_ap = va_arg(*ap, size_t*);
	else
		temp_ap = va_arg(*ap, int*);
	if (temp_ap)
		*temp_ap = (uintmax_t) flag.lenght_print;
}

short		handle_intmax_min(char	*stock_number, t_flag *flag)
{
	char		i;

	stock_number[3] = '1';
	i = 4;
	while(i <= 66)
		stock_number[i++] = '0';
	flag->binary = 1;
	return (2);
}

short		annex_convert_dec_to_binary(char *stock_number,intmax_t nbr, t_flag *flag)
{
	intmax_t nb;
	short    i;

	i = 66;
	if (nbr == 0 && flag->precision != 0)
		stock_number[i--] = '0';
	else if (nbr == -9223372036854775808)
		i = handle_intmax_min(stock_number, flag);
	else
	{
		if (nbr < 0)
			nb = -nbr;
		else
			nb = nbr;
		if (nb != 0)
		{
			flag->binary = 1;
			while (nb > 0)
			{
				stock_number[i--] = (char) ((nb % 2) + '0');
				nb = nb / 2;
			}
		}
	}
	return (i);
}

size_t		convert_dec_to_binary(intmax_t nbr, t_flag flag)
{
	char	stock_number[67];
	short	i;
	size_t	total_len;

	i = annex_convert_dec_to_binary(&stock_number, nbr, &flag);
	if (flag.hash == 2 && nbr != 0)
	{
		stock_number[i--] = 'b';
		stock_number[i--] = '0';
	}
	if (nbr < 0)
		stock_number[i--] = '-';
	else if (flag.more == 1)
		stock_number[i--] = '+';
	total_len = print_final_result(flag, &stock_number[i + 1], 66 - i);
	return (total_len);
}

 