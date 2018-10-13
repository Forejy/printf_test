#include <unistd.h>
#include "../../Includes/Handlers/handlers.h"
#include "../../Includes/Print_Final_Result/print_and_compute_final_result.h"

size_t	my_strlen(const char *str)
{
	size_t		i;

	i = 3;
	while (1)
	{
		if (str[i - 3] == '\0')
			return (i - 3);
		else if (str[i - 2] == '\0')
			return (i - 2);
		else if (str[i - 1] == '\0')
			return (i - 1);
		else if (str[i] == '\0')
			return (i);
		i += 4;
	}
}

int		my_putchar_printf(char c, t_flag flag)
{
	int			total_len;

	flag.character_or_string = 1;
	if (flag.champs == 0)
	{
		write(1, flag.buffer, flag.len_buffer);
		write(1, &c, 1);
		return (1);
	}
	else
		total_len = print_final_result(flag, &c, 1);
	return(total_len);
}

size_t	annex_to_putstr_printf(const char* str, t_flag flag, size_t len_str)
{
	int			flag_precision;
	size_t		total_len;

	flag_precision = flag.precision;
	if (str == NULL)
	{
		if (flag_precision > 6 || flag_precision == -1)
			flag_precision = 6;
		write(1, flag.buffer, flag.len_buffer);
		write(1, "(null)", flag_precision);
		total_len = flag_precision;
	}
	else
	{
		if (flag_precision > -1 && flag_precision < (int) len_str)
			len_str = (size_t) flag_precision;
		write(1, flag.buffer, flag.len_buffer);
		write(1, str, len_str);
		total_len = len_str;
	}
	return  (total_len);
}


int		my_putstr_printf(const char* str, t_flag flag)
{
	size_t		len_str;
	size_t		total_len;

	len_str = 0;
	if (str != NULL)
		len_str = my_strlen(str);
	flag.character_or_string = 2;
	if (flag.champs == 0)
	{
		total_len = annex_to_putstr_printf(str, flag, len_str);
		return (total_len);
	}
	else if (str == NULL)
		return(print_final_result(flag, "(null)", 6));
	else
		total_len = print_final_result(flag, str, len_str);
	return (total_len);
}

size_t	my_putstr(const char *str)
{
	size_t				total_len;

	total_len = my_strlen(str);
		write(1, str, total_len);
	return(total_len);
}
