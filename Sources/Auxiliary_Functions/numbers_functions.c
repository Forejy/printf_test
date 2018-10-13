#include <unistd.h>
#include "../../Includes/Handlers/handlers.h"
#include "../../Includes/Print_Final_Result/print_and_compute_final_result.h"

size_t		my_putnbr_long_long(intmax_t nbr, t_flag flag)
{
	char			stock_number[20];
	int				i;
	uintmax_t		nb;
	size_t				total_len;

	flag.conv_d = 1;
	i = 19;
	if (nbr < 0)
		nb = -nbr;
	else
		nb = nbr;
	if (nb == 0 && flag.precision != 0)
		stock_number[i--] = '0';
	while (nb > 0)
	{
		stock_number[i] = (char) ((nb % 10) + '0');
		nb = nb / 10;
		i--;
	}
	if (nbr < 0)
		stock_number[i--] = '-';
	if (nbr >= 0 && flag.more)
		stock_number[i--]= '+';
	total_len = print_final_result(flag, &stock_number[i + 1], 19 - i);
	return (total_len);
}

size_t			my_put_unsigned_long_long(uintmax_t nbr, t_flag flag)
{
	char			stock_number[20];
	int				i;
	size_t			total_len;

	i = 19;
	if (nbr == 0 && flag.precision != 0)
	{
		stock_number[i] = '0';
		i--;
	}
	while (nbr > 0)
	{
		stock_number[i] = (char) ((nbr % 10) + '0');
		nbr = nbr / 10;
		i--;
	}
	total_len = print_final_result(flag, &stock_number[i + 1], 19 - i);
	return (total_len);
}

size_t			my_putnbr_hexa(uintmax_t nb, t_flag flag)
{
	char		stock_number[20];
	int			i;
	char		*base_hexa;
	size_t		total_len;

	base_hexa = "0123456789abcdef";
	i = 19;
	total_len = 0;
	if (nb == 0 && flag.precision != 0)
		stock_number[i--] = '0';
	else if(nb != 0)
	{
		while (nb > 0)
		{
			stock_number[i--] = base_hexa[(nb % 16)];
			nb = (nb / 16);
		}
		if ((flag.hexa = 2) && flag.hash == 2)
		{
			stock_number[i--] = 'x';
			stock_number[i--] = '0';
		}
	}
	total_len = total_len + print_final_result(flag, &stock_number[i + 1], 19 - i);
	return (total_len);
}

size_t			my_putnbr_HEXA(uintmax_t nb, t_flag flag)
{
	char		stock_number[20];
	int			i;
	char		*base_hexa;
	size_t			total_len;

	base_hexa = "0123456789ABCDEF";
	i = 19;
	total_len = 0;
	if (nb == 0 && flag.precision != 0)
		stock_number[i--] = '0';
	else if (nb != 0)
	{
		while (nb > 0)
		{
			stock_number[i--] = base_hexa[(nb % 16)];
			nb = (nb / 16);
		}
		if ((flag.hexa = 2) && flag.hash == 2)
		{
			stock_number[i--] = 'X';
			stock_number[i--] = '0';
		}
	}
	total_len = total_len + print_final_result(flag, &stock_number[i + 1], 19 - i);
	return (total_len);
}

size_t			my_put_octal(uintmax_t nbr, t_flag flag)
{
	char		stock_number[23];
	int			i;
	size_t			total_len;

	i = 22;
	flag.octal = 1;
	if (nbr == 0 && flag.precision == -1)
		stock_number[i--] = '0';
	else
	{
		while (nbr > 0)
		{
			stock_number[i] = (char) ((nbr % 8) + '0');
			nbr = nbr / 8;
			i--;
		}
		if (flag.hash == 2)
		{
			stock_number[i] = '0';
			i--;
		}
	}
	total_len = print_final_result(flag, &stock_number[i + 1], 22 - i);
	return (total_len);
}