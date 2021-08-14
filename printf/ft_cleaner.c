#include "ft_printf.h"

void	ft_cleaner(t_list *argv)
{
	argv->start = 0;
	argv->specifier = 0;
	argv->value = 0;
	argv->value_len = 0;
	argv->rawstr = 0;
	argv->sign = "";
	argv->size = "";
	argv->flag_minus = 0;
	argv->flag_zero = 0;
	argv->width = 0;
	argv->dot = 0;
	argv->precision = 0;
	argv->precision_if_negative = 0;
}
