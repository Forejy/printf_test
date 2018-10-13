#include <wchar.h>

int 	test_validity_of_characters(wchar_t *string_wchar)
{
	int i;
	wint_t temp;

	i = 0;
	while ((temp = string_wchar[i]) != '\0')
	{
		if ((temp > 1114111 || temp < 0) || (temp >= 55296 && temp <= 57343))
			return (-1);
		i++;
	}
	return (1);
}

unsigned int				compute_minimum_number_of_bits(unsigned int n)
{
	unsigned int		pow2;
	unsigned int		k;

	pow2 = 1;
	k = 0;
	while (n >  pow2)
	{
		pow2 = 2 * pow2;
		k++;
	}
	return (k);
}

int				compute_minimum_number_of_bytes_in_utf8(int decimal)
{
	int		numb_of_bits;

	numb_of_bits = compute_minimum_number_of_bits(decimal);
	if (numb_of_bits <= 7)
		return (1);
	else if (numb_of_bits <= 11)
		return (2);
	else if (numb_of_bits <= 16)
		return (3);
	else if (numb_of_bits <= 21)
		return (4);
	else if (numb_of_bits <= 26)
		return (5);
	else// (numb_of_bits <= 31)
		return (6);
}

int				compute_power(int base, unsigned int exposant)
{
	int		result;

	if (exposant == 0)
		return (1);
	result = 1;
	while (exposant > 0)
	{
		result = result * base;
		exposant--;
	}
	return (result);
}