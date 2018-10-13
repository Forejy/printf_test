#ifndef STRINGS_FUNCTIONS_H
# define STRINGS_FUNCTIONS_H

# include <unistd.h>
# include <inttypes.h>
# include "../Handlers/handlers.h"

size_t		my_putstr(const char *str);
size_t		my_putstr_printf(const char *str, t_flag flag);
size_t		my_putchar_printf(char c, t_flag flag);
size_t		my_strlen(const char *str);

#endif //PRINTF_FUNCTIONS_H
