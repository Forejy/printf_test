#include "../../Includes/Handlers/handlers.h"

int		compute_padding_conv_f(t_flag flag, int len_arg)
{
	int		len_padding;
	int		len_champs;
	int		len_precision;

	len_padding = 0;
	len_champs = flag.champs;
	len_precision = flag.precision;
	if (len_precision == -1 && len_champs > 0)
		len_padding = len_champs - len_arg;
	else if (len_precision == 0 && len_champs == (flag.conv_f_intpart + 1))
		len_padding = 1;
	else if (len_precision == 0)
		len_padding = len_champs - flag.conv_f_intpart;
	else if (len_precision > 0 && flag.champs > flag.conv_f_intpart + 1 + len_precision)
		len_padding = len_champs - (flag.conv_f_intpart + 1) - len_precision ;
	return (len_padding);
}

int			compute_padding(const char *stock, t_flag f, int len_prec, int len_arg)
{
	int			len_padding;
	int			len_champs;

	len_champs = f.champs;
	len_padding = -1;
	if (f.conv_f)
		len_padding = compute_padding_conv_f(f, len_arg);
	else if (f.hash == 2 && (f.hexa == 2 || f.binary) && len_prec > len_arg - 2)
		len_padding = len_champs - len_prec - 2;
	else if (len_prec >= (len_arg - f.pointer) && f.character_or_string == 0
			 && f.unicode_c == 0 && f.unicode_s == 0)
	{
		len_padding = len_champs - len_prec;
		if (*stock == '-' || (*stock == '+'))
			len_padding -= 1;
	}
	else if (len_prec >= 0 && len_prec <= len_arg && (f.character_or_string == 2
													  || f.unicode_c || f.unicode_s))
		len_padding = len_champs - len_prec;
	else if (!f.unicode_s || (f.unicode_s && len_champs > len_arg))
		len_padding = len_champs - len_arg + f.pointer;
	if (stock && *stock != '+' && *stock != '-' && f.less
		&& f.blank && (f.conv_d || f.conv_f_intpart))
		len_padding -= 1;
	return (len_padding - f.pointer);
}

uintmax_t		compute_total_len_conv_f(t_flag flag, int len_padding, int len_prec, int len_arg)
{
	uintmax_t		total_len;

	total_len = 0;
	if (len_padding > 0 && len_prec > 0)
		total_len += len_padding + flag.conv_f_intpart + 1 + flag.precision;
	else if (len_padding > 0 && len_prec == 0)
		total_len += len_padding + flag.conv_f_intpart;
	else if (len_padding <= 0 && len_prec > 0)
		total_len += flag.precision + flag.conv_f_intpart + 1;
	else if (len_prec == -1)
		total_len += len_arg + len_padding;
	else
		total_len += flag.conv_f_intpart + (flag.hash/2);
	return (total_len);
}

uintmax_t		cmpt_totlen(t_flag flag, int len_padding, int len_prec, int len_arg)
{
	uintmax_t		total_len;

	total_len = 0;
	if (len_padding < 0)
		len_padding = 0;
	if (flag.conv_f)
		total_len += compute_total_len_conv_f(flag, len_padding, len_prec, len_arg);
	else if (((flag.hexa || flag.binary) && (len_prec > (len_arg - flag.hash)
			|| len_prec > len_arg )) || (((flag.character_or_string == 2 || flag.unicode_s) && (len_prec != -1 
			|| (flag.unicode_c && len_prec > 0))) && len_prec < len_arg)
			|| ((!flag.hexa || !flag.binary) && !flag.unicode_s && !flag.unicode_c && !flag.character_or_string
			&& len_prec > len_arg))
		total_len += (size_t)len_padding + (size_t)len_prec;
	else if (flag.character_or_string == 2 && len_prec == 0)
		total_len += len_padding;
	else
		total_len += (size_t)len_padding + (size_t)len_arg;
	return (total_len);
}
