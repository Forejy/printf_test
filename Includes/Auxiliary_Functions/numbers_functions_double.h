#include "../Handlers/handlers.h"

#ifndef NUMBERS_FUNCTIONS_DOUBLE_H
# define  NUMBERS_FUNCTIONS_DOUBLE_H

unsigned long long		power_of_10(int n);
int						pdl(unsigned long long it, unsigned long long *dt, t_flag f, double n);
size_t					anx_2_putdouble(double nbr, t_flag flag, char *stock_number, int i);
size_t					pdl2(int	i, t_flag flag, unsigned long long dec_part, double nbr);
size_t					my_putnbr_double(double nbr, t_flag flag);


#endif
