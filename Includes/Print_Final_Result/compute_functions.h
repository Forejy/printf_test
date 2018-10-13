#ifndef COMPUTE_FUNCTIONS_H
# define COMPUTE_FUNCTIONS_H

#include "../Handlers/handlers.h"

int			compute_padding(const char *stock, t_flag f, int len_prec, int len_arg);
uintmax_t		cmpt_totlen(t_flag flag, int len_padding, int len_prec, int len_arg);

#endif