#ifndef CONVERT_DEC_TO_BIN_UTF8_H
# define CONVERT_DEC_TO_BIN_UTF8_H
# include "create_and_print_t_bin_list.h"

t_bin_list			*call_functions_to_convert_dec_to_bin_in_utf8(int dec, int number_of_bytes);
void			*convert_bin_to_dec(t_bin_list *begin_list);
void			convert_dec_to_bin_utf8(int	number_of_bytes, t_bin_list *begin_bin_list, int dec);

#endif
