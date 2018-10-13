#ifndef ANNEX_FUNCTIONS_H
# define ANNEX_FUNCTIONS_H

#include "../Handlers/handlers.h"

int		annex_to_print_padding(t_flag f, const char **stock, int len_padding);
int		a2_print_rlt_wp(t_flag f, const char **stock, int *len_argument, int sign);
void	a3_print_rlt_wp(t_flag flag, const char *stock, int len_argument, int len_precision);


#endif