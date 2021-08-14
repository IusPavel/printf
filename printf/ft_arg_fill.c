#include "ft_printf.h"

static int	is_flag(char c)
{
	return (c == 'd' || c == 'i' || c == 'u' || c == 'x' || c == 'X'
		|| c == 'c' || c == 's' || c == 'p' || c == '%');
}

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

void	ft_arg_fill_bonus(char c, t_list *argv)
{
	if (c == '+')
		argv->sign = "+";
	else if ((c == ' ') && ft_strcmp(argv->sign, "+"))
		argv->sign = " ";
	else if (c == '#')
		argv->sign = "#";
	else if (c == 'l' && !ft_strcmp(argv->size, "l"))
		argv->size = "ll";
	else if (c == 'l')
		argv->size = "l";
	else if (c == 'h' && !ft_strcmp(argv->size, "h"))
		argv->size = "hh";
	else if (c == 'h')
		argv->size = "h";
}

void	ft_arg_fill(char c, t_list *argv, va_list ap)
{
	if (is_flag (c))
		argv->specifier = c;
	else if (c == '-' && argv->dot == 0)
		argv->flag_minus = 1;
	else if (c == '-' && argv->dot == 1)
		argv->precision_if_negative = 1;
	else if (c == '0' && argv->precision == 0 && argv->width == 0)
		argv->flag_zero = 1;
	else if (c == '.')
		argv->dot = 1;
	else if (is_digit(c) && argv->dot == 0)
		argv->width = ((argv->width) * 10) + (c - '0');
	else if (c == '*' && argv->dot == 0)
		argv->width = va_arg(ap, int);
	else if (c == '*' && argv->dot == 1)
		argv->precision = va_arg(ap, int);
	else if (is_digit(c) && argv->dot == 1)
		argv->precision = ((argv->precision) * 10) + (c - '0');
	ft_arg_fill_bonus(c, argv);
}
