#ifndef CHAIN_LIST_FUNCTIONS_H
#define CHAIN_LIST_FUNCTIONS_H
# define DECIMAL 10
# define BINARY 2

typedef struct		s_bin_list
{
	unsigned char		binary[9];
	struct s_bin_list	*next;
}					t_bin_list;

t_bin_list		*create_and_initialize_t_bin_list(int	number_of_byte);
void			print_list(t_bin_list *begin_list, unsigned int representation_of_number);


#endif
