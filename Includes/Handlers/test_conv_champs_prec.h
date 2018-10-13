#ifndef TEST_CONV_CHAMPS_PREC_H
# define TEST_CONV_CHAMPS_PREC_H

#include "handlers.h"

int			test_flag(char format_flag, t_flag	*flag);
int			test_precision(const char *format, t_flag *flag, va_list *ap);
int			test_champs(const char *format, t_flag *flag, va_list *ap);
short		test_if_conv(char conv, t_flag *flag, short i);

#endif