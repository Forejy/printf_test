#include "../../Includes/Print_Unicode/create_and_print_t_bin_list.h"
#include "../../Includes/Handlers/handlers.h"
#include "../../Includes/Print_Unicode/auxiliary_functions_for_unicode.h"



void			convert_bin_to_dec(t_bin_list *begin_list)
{
	t_bin_list	*temp;
	int			i;
	int			n;

	temp = begin_list;
	while (temp)
	{
		i = 7;
		n = 0;
		while (i >= 0)
		{
			n =  n +(temp->binary[i] - '0') * compute_power(2, 7 - i);
			i--;
		}
		temp->binary[0] = (unsigned char)n;
		temp->binary[1] = 0;
		temp = temp->next;
	}
}

void	annex_to_convert_dectobin(int i, int n_bytes, t_bin_list *b_list, int dec)
{
	int		j;

	while (i <= n_bytes)
	{
		if ((j = 7) && i++ == n_bytes)
		{
			while (j > n_bytes)
			{
				b_list->binary[j--] = (unsigned char) (char)(dec % 2 + 48);
				dec = dec / 2;
			}
			while (--j >= 0)
				b_list->binary[j] = '1';
		}
		else
		{
			(b_list->binary)[0] = '1';
			while (j >= 2)
			{
				b_list->binary[j--] = (unsigned char)(dec % 2 + 48);
				dec = dec / 2;
			}
		}
		b_list = b_list->next;
	}
}

void			convert_dec_to_bin_utf8(int	number_of_bytes, t_bin_list *begin_bin_list, int dec)
{
	t_bin_list	*temp;
	int			i;
	int			j;

	temp = begin_bin_list;
	i = 1;
	if (number_of_bytes != 1)
		annex_to_convert_dectobin(i, number_of_bytes, begin_bin_list, dec);
	else
	{
		j = 7;
		while (j >= 0)
		{
			temp->binary[j--] = (unsigned char)(dec % 2 + 48);
			dec = dec / 2;
		}
	}
}

t_bin_list		*call_functions_to_convert_dec_to_bin_in_utf8(int dec, int number_of_bytes)
{
	t_bin_list	*begin_list;

	begin_list = create_and_initialize_t_bin_list(number_of_bytes);
	convert_dec_to_bin_utf8(number_of_bytes, begin_list, dec);
	convert_bin_to_dec(begin_list);
	return (begin_list);
}

/*
 * Remplit les octets en convertissant le nombre decimal en binaire, au format UTF8
 */
