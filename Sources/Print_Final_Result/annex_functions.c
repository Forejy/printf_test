#include "../../Includes/Handlers/handlers.h"

int		annex_to_print_padding(t_flag f, const char **stock, int len_padding)
{
	int		retenue;
	int		f_pointer;

	retenue = 0;
	f_pointer = f.pointer;
	if (((f.precision >= 0 && !f.character_or_string && !f.unicode_s
		  &&(!f.blank || (f.blank && f.zero))) || !f.zero || (f.zero && f.less))
		&& !(f.conv_f && f.zero) || (f.conv_f && f.less))
		while (len_padding-- > 0)
			write(1, " ", 1);
	else if ((f.zero || f.precision >= 0) && (f_pointer == 2 || f.hexa == 2
			|| f.binary)  && !f.less && (((f.hexa || f.binary) && f.hash == 2)
			| (!f.hexa && !f.binary)))
	{
		write(1, *stock, 2);
		*stock = *stock + 2;
		retenue += 2;
		if (f.precision <= 0)
			while (len_padding-- > 0)
				write(1, "0", 1);
	}
	else if (f.zero && !f.less)
		while (len_padding-- > 0)
			write(1, "0", 1);
	return (retenue);
}

int		a2_print_rlt_wp(t_flag f, const char **stock, int *len_argument, int sign)
{
	int		temp;
	int		len_precision;
	int 	ret;

	len_precision = f.precision;
	ret = 0;
	if (len_precision > 0 && (len_precision > *len_argument - f.hexa - f.binary)
		&& (f.pointer == 2 || ((f.hexa == 2 || f.binary) && f.hash)))
	{
		write(1, *stock, 2);
		*stock = *stock + 2;
		*len_argument -= 2;
		ret += 2;
	}
	temp = len_precision - *len_argument;
	if ((len_precision >= f.champs || *len_argument >= f.champs  || f.less)
		&& f.blank && !sign && stock && *stock && **stock != '-' && **stock != '+')
	{
		write(1, " ", 1);
		ret += 1;
	}
	while (temp-- > 0)
		write(1, "0", 1);
	return (ret);
}

void		a3_print_rlt_wp(t_flag flag, const char *stock, int len_argument, int len_prec)
{
	int		i;
	
	i = 0;
	if (stock && (flag.character_or_string == 2 || flag.unicode_c 
		|| flag.unicode_s) 
		&& len_prec >= 0 && len_prec < len_argument && !flag.conv_f)
		write(1, stock, (size_t) (len_prec));
	else if (flag.unicode_c == 1)
		while (len_argument > 0)
			write(1, &stock[len_argument-- - 1], 1);
	else if (flag.unicode_s == 1)
		while(i < len_argument)
			write(1, &stock[i++], 1);
	else if (stock && len_argument > 0 && !flag.conv_f)
		write(1, stock, (size_t) (len_argument));
}