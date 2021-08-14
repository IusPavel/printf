#include "ft_printf.h"

void	ft_exception(t_list *argv)
{
	if (argv->width < 0)
	{
		argv->width *= -1;
		argv->flag_minus = 1;
	}
	if (argv->flag_minus == 1)
		argv->flag_zero = 0;
	if ((argv->specifier == 'd' || argv->specifier == 'i'
			|| argv->specifier == 'o' || argv->specifier == 'x'
			|| argv->specifier == 'X' || argv->specifier == 'u')
		&& argv->dot == 1 && argv->precision >= 0)
		argv->flag_zero = 0;
	if (argv->precision_if_negative == 1)
		argv->precision *= -1;
	if (!ft_strcmp(argv->sign, "#") && (argv->specifier == 'd'
			|| argv->specifier == 'i' || argv->specifier == 'u'))
		argv->sign = "";
}
