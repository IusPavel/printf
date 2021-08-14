#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	t_list	argv;
	va_list	ap;

	ft_cleaner(&argv);
	argv.counter = 0;
	va_start(ap, format);
	while (ft_distributor(*format, &argv, ap))
		format++;
	va_end(ap);
	return (argv.counter);
}
