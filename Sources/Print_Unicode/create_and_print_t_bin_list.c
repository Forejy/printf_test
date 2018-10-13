#include <stdlib.h>
#include "../../Includes/Print_Unicode/create_and_print_t_bin_list.h"
#include "../../Includes/Auxiliary_Functions/numbers_functions.h"
#include "../../Includes/errors.h"

void			initialize_t_bin_list_elem(t_bin_list *elem)
{
	int			i;

	i = 7;
	while (i >= 0)
	{
		elem->binary[i] = '0';
		i--;
	}
	elem->next = NULL;
}
/*
 * Create a t_bin_list element for the chain list used during the conversion char to binary
 */

t_bin_list		*create_and_initialize_t_bin_list(int	number_of_byte)
{
	t_bin_list	*begin_list;
	t_bin_list	*temp;

	if (!(begin_list = (t_bin_list *)malloc(sizeof(t_bin_list))))
		exit_with_msg(ERROR_MALLOC_FAILED);
	temp = begin_list;
	initialize_t_bin_list_elem(temp);
	while(number_of_byte - 1 > 0)
	{
		if (!(temp->next = (t_bin_list *)malloc(sizeof(t_bin_list))))
			exit_with_msg(ERROR_MALLOC_FAILED);
		temp = temp->next;
		initialize_t_bin_list_elem(temp);
		number_of_byte--;
	}
	return (begin_list);
}

/*
 * Create the chain list to stock the conversion char to binary formatted in UTF8
 */