#ifndef NUMBERS_FUNCTIONS_H
# define NUMBERS_FUNCTIONS_H

#include "../Handlers/handlers.h"

size_t			my_putnbr_long_long(intmax_t nb, t_flag flag);
size_t			my_put_unsigned_long_long(uintmax_t nbr, t_flag flag);
size_t			my_putnbr_HEXA(uintmax_t nb, t_flag flag);
size_t			my_putnbr_hexa(uintmax_t nb, t_flag flag);
size_t			my_put_octal(uintmax_t nb, t_flag flag);

#endif

