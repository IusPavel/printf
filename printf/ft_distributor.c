#include "ft_printf.h"

int	ft_distributor(char c, t_list *argv, va_list ap)
{
	if (c == '\0')
		return (0);
	if ((c == '%') && (argv->start == 0))
	{
		argv->start = 1;
		return (1);
	}
	else if (argv->start == 1)
		ft_arg_fill(c, argv, ap);
	else if (argv->start == 0)
	{
		ft_putchar(c);
		(argv->counter)++;
	}
	if (argv->specifier != 0)
	{
		ft_exception(argv);
		ft_release(argv, ap);
	}
	return (1);
}
