#include "../../Includes/Handlers/handlers.h"
#include "../../Includes/Print_Final_Result/compute_functions.h"
#include "../../Includes/Print_Final_Result/annex_functions.h"

int		print_padding(t_flag flag, const char **stock, int len_padding)
{
	int		retenue;

	retenue = 0;
	if (!flag.less && *stock && (**stock == '-' || **stock == '+')
		&& flag.character_or_string == 0
		&& !(len_padding > 0 && !flag.zero) && flag.precision < 0)
	{
		write(1, *stock, 1);
		(*stock)++;
		retenue++;
	}
	if (len_padding > 0)
	{
		if ((flag.zero && flag.blank && (flag.conv_d || flag.conv_f) && !retenue )
			|| flag.less)
		{
			len_padding -= 1;
			write(1, " ", 1);
		}
		retenue += annex_to_print_padding(flag, stock, len_padding);
	}
	return (retenue);
}
/*
 * 			//Dans le cas des pointeurs :
				//Si on a champs et precision en meme temps 
				// le 0x doit etre imprime avant l'appel de la precision :'    0x''000000000000ffffcb84' 'padding''precision'
				//Si on a flag.zero 
				// le 0x doit etre imprime avant le rembourrage par 0 : 0x000000000000ffffcb84
 */

int		print_convf_wp(t_flag f, const char *s, int len_prec, int *sign, int ret)
{
	int		len_int_part;

	len_int_part = f.conv_f_intpart;
	if ((len_prec > 0 && (f.champs < (f.conv_f_intpart + 1 + len_prec)
		&& f.blank)) || ((len_prec >= f.champs || f.conv_f_intpart >= f.champs
		|| f.less) && f.blank && s && *s != '-' && *s != '+'))
	{
		write(1, " ", 1);
		ret += 1;
	}
	if (f.precision > 0)
	{
		write(1, s, len_int_part + 1);
		if (len_prec > 0 && len_prec <= 15)
			write(1, &s[len_int_part + 1], len_prec);
		else
		{
			write(1, &s[len_int_part + 1], 15);
			while (len_prec-- > 15)
				write(1, "0", 1);
		}
	}
	else if (f.precision == 0)
		write(1, s, len_int_part + f.hash/2);
	return (ret);
}


int		print_result_w_precision(t_flag flag, const char *stock, int len_argument)
{
	int		ret;
	int 	sign;
	int 	len_precision;

	ret = 0;
	sign = 0;
	len_precision = flag.precision;
	if (flag.conv_f)
		ret += print_convf_wp(flag, stock, len_precision, &sign, ret);
	if (flag.character_or_string == 0 && stock && (*stock == '-' || *stock == '+')
		&& (len_precision >= len_argument && !flag.conv_f))
	{
		write(1, stock, 1);
		stock++;
		len_argument--;
		sign = 1;
	}
	if (flag.character_or_string == 0 && flag.unicode_c == 0
		&& flag.unicode_s == 0 && !flag.conv_f)
		ret += a2_print_rlt_wp(flag, &stock, &len_argument, sign);
	a3_print_rlt_wp(flag, stock, len_argument, len_precision);
	return(ret + sign);
}

int			print_result_w_no_precision(t_flag flag, const char *stock, int len_arg)
{
	int		i;
	int 	ret;

	i = 0;
	ret = 0;
	if ((flag.conv_d || flag.conv_f) && flag.blank && *stock != '-'
		&& *stock != '+' && (flag.champs <= len_arg || flag.less))
	{
		write(1, " ", 1);
		ret++;
	}
	if (flag.unicode_c == 1)
		while (len_arg > 0)
			write(1, &stock[len_arg-- - 1], 1);
	else if (flag.unicode_s == 1)
		while(i < len_arg)
			write(1, &stock[i++], 1);
	else if (stock)
		write(1, stock, len_arg);
	return(ret);
}


intmax_t		print_final_result(t_flag flag, const char *stock, int len_argument)
{
	int						len_precision;
	int						len_padding;
	uintmax_t				total_len;
	int						sign;

	len_padding = -1;
	len_precision = flag.precision;
	total_len = 0;
	sign = 0;
	write(1, flag.buffer, flag.len_buffer);
	if(flag.champs > 0)
		len_padding = compute_padding(stock, flag, len_precision, len_argument);
	if (len_padding > 0 && flag.less == 0)
	{
		sign = print_padding(flag, &stock, len_padding);
		len_argument = len_argument - sign;
	}
	if (len_precision != -1)
		total_len += print_result_w_precision(flag, stock, len_argument);
	else
		total_len += print_result_w_no_precision(flag, stock, len_argument);
	if (len_padding >= 0 && flag.less == 1)
		print_padding(flag, &stock, len_padding);
	total_len += cmpt_totlen(flag, len_padding, len_precision, len_argument);
	return (total_len + sign);
}
