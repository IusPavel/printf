#include "ft_printf.h"

static void	str_fill(t_list *argv)
{
	size_t	len;
	size_t	i;
	size_t	k;
	int		q;

	i = 0;
	k = 0;
	q = 0;
	len = 1;
	if (len < (size_t)argv->width && argv->flag_zero == 1)
		len = argv->width;
	if (argv->flag_minus == 0)
		i = ft_strlen(argv->value) - len;
	argv->value[i] = argv->rawstr[q];
}

static void	str_initial(t_list *argv)
{
	char	init;
	size_t	i;
	size_t	len;

	i = 0;
	len = 1;
	if (len < (size_t)argv->width)
		len = argv->width;
	argv->value = (char *)malloc(sizeof(char) * (len + 1));
	argv->value[len] = '\0';
	init = ' ';
	if (argv->flag_zero == 1)
		init = '0';
	while (i < len)
		argv->value[i++] = init;
	argv->value_len = ft_strlen(argv->value);
}

void	ft_release_c(t_list *argv, int result)
{
	argv->rawstr = ft_ctoa(result);
	str_initial(argv);
	str_fill(argv);
	ft_print_arg(argv);
	if (argv->value != 0)
		free(argv->value);
	if (argv->rawstr != 0)
		free(argv->rawstr);
	ft_cleaner(argv);
}
