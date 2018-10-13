#include <stdarg.h>
#include "../Includes/printf.h"
#include "../Includes/Handlers/handlers.h"

int			ft_printf(const char *format, ...)
{
	int			ret;

	va_list		ap;
	va_start(ap, format);
	ret = handle_format(format, &ap);
	return (ret);
}