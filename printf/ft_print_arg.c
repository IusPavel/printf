#include "ft_printf.h"

void	ft_print_arg(t_list *argv)
{
	int	i;

	i = 0;
	while ((argv->value_len)--)
	{
		ft_putchar(argv->value[i]);
		(argv->counter)++;
		i++;
	}
}
