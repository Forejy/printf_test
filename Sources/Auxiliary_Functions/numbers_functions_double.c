#include "../../Includes/Print_Final_Result/print_and_compute_final_result.h"

unsigned long long		power_of_10(int n)
{
	unsigned long long			power;

	power = 1;
	if (n <= 0)
		power = 1;
	while (n-- > 0)
		power = power * 10;
	return (power);
}


int						pdl(unsigned long long it, unsigned long long *dt, t_flag f, double n)
{
	unsigned long long		temp_dec_part;
	double					dbl_dec_part;
	double					nb;
	int						len_dec_part;

	if (n < 0)
		nb = -n;
	else
		nb = n;
	dbl_dec_part = (nb - it) * 1000000000000000;
	temp_dec_part = dbl_dec_part;
	len_dec_part = f.precision <= 15 ? f.precision : 15;
	len_dec_part = len_dec_part == -1 ? 6 : len_dec_part;
	if (len_dec_part > 0 && dt != 0)
	{
		temp_dec_part = temp_dec_part / power_of_10(14 - len_dec_part);
		if (temp_dec_part % 10 >= 5 && f.precision <= 15)
			temp_dec_part = temp_dec_part / 10 + 1;
		else if (f.precision <= 15)
			temp_dec_part = temp_dec_part / 10;
	}
	*dt = temp_dec_part;
	return(20 + len_dec_part);
}

size_t					anx_2_putdouble(double nbr, t_flag flag, char *stock_number, int i)
{
	int			len_dec_part;

	len_dec_part = flag.precision <= 15 ? flag.precision : 15;
	len_dec_part = len_dec_part == -1 ? 6 : len_dec_part;
	if (nbr < 0)
		stock_number[i--] = '-';
	if (nbr >= 0 && flag.more)
		stock_number[i--]= '+';
	if (nbr < 0 || (nbr >= 0 && flag.more))
		flag.conv_f_intpart += 1;
	flag.conv_f = 1;
	return(print_final_result(flag, &stock_number[i + 1], len_dec_part + flag.conv_f_intpart + 1));
}

size_t					pdl2(int	i, t_flag flag, unsigned long long dec_part, double nbr)
{
	char	stock_number[36];
	unsigned long long		int_part;

	int_part = nbr < 0 ? - nbr : nbr;
	if (dec_part == 0)
		while (i > 20)
			stock_number[i--] = '0';
	while (dec_part > 0)
	{
		stock_number[i--] = (char) ((dec_part % 10) + '0');
		dec_part = dec_part / 10;
	}
	if(!(flag.precision == 0 && !flag.hash && (i = 20)))
		stock_number[i--] = '.';
	if (int_part == 0 && (i = 19))
		stock_number[i--] = '0';
	while (int_part > 0)
	{
		stock_number[i--] = (char) ((int_part % 10) + '0');
		int_part = int_part / 10;
		flag.conv_f_intpart++;
	}
	return (anx_2_putdouble(nbr, flag, stock_number, i));
}

size_t					my_putnbr_double(double nbr, t_flag flag)
{
	unsigned long long		int_part;
	unsigned long long		dec_part;
	int			i;

	int_part = nbr < 0 ? - nbr : nbr;
	i = pdl(int_part, &dec_part, flag, nbr);
	if (int_part == 0)
		flag.conv_f_intpart++;
	return (pdl2(i, flag, dec_part, nbr));
}
