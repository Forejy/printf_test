#include <unistd.h>
#include "../../Includes/Print_Final_Result/print_and_compute_final_result.h"

size_t	my_putaddress(uintmax_t nb, t_flag flag)
{
	char		stock_number[20];
	int			i;
	char		*base_hexa;
	size_t			total_len;

	base_hexa = "0123456789abcdef";
	i = 19;
	flag.pointer = 2;
	if (nb == 0 && flag.precision != 0)
		stock_number[i--] = '0';
	while (nb > 0)
	{
		stock_number[i] = base_hexa[(nb % 16)];
		nb = (nb / 16);
		i--;
 	}
	stock_number[i--] = 'x';
	stock_number[i--] = '0';
	total_len = print_final_result(flag, &stock_number[i + 1], 19 - i);
	return (total_len);
}