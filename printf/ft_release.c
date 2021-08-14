#include "ft_printf.h"

void	ft_release(t_list *argv, va_list ap)
{
	if (argv->specifier == 'd' || argv->specifier == 'i')
		ft_release_di(argv, va_arg(ap, long long int));
	if (argv->specifier == 'u')
		ft_release_u(argv, va_arg(ap, unsigned long long int));
	if (argv->specifier == 'x')
		ft_release_x(argv, va_arg(ap, unsigned long long int));
	if (argv->specifier == 'X')
		ft_release_xx(argv, va_arg(ap, unsigned long long int));
	if (argv->specifier == 'c')
		ft_release_c(argv, va_arg(ap, int));
	if (argv->specifier == 's')
		ft_release_s(argv, va_arg(ap, char *));
	if (argv->specifier == 'p')
		ft_release_p(argv, va_arg(ap, unsigned long long int));
	if (argv->specifier == '%')
		ft_release_percent(argv);
}
