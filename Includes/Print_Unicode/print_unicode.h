#ifndef PRINT_UNICODE_H
# define PRINT_UNICODE_H

#include <wchar.h>
#include "create_and_print_t_bin_list.h"
#include "../Handlers/handlers.h"

intmax_t			my_put_wint_t(int dec, t_flag flag);
intmax_t			my_put_wchar_t(wchar_t *string_wchar, t_flag flag);
int					count_char_per_wint_t(t_flag flag, wchar_t *string_wchar, int **number_of_char_per_wint_t);

#endif