#include "ft_printf.h"

static void	str_fill(t_list *argv)
{
	size_t	len;
	size_t	i;
	size_t	k;
	int		q;

	k = 0;
	i = 0;
	q = 0;
	len = ft_strlen(argv->rawstr);
	if (len < (size_t)argv->width && argv->flag_zero == 1)
		len = argv->width;
	if (argv->flag_minus == 0)
		i = ft_strlen(argv->value) - len;
	if (len > ft_strlen(argv->rawstr))
		while ((len-- - ft_strlen(argv->rawstr)) > 0)
			argv->value[i++] = '0';
	while (argv->rawstr[q])
		argv->value[i++] = argv->rawstr[q++];
}

static void	str_initial(t_list *argv)
{
	char	init;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(argv->rawstr);
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

void	ft_release_s(t_list *argv, char *result)
{
	if (!result)
	{
		if (argv->dot == 0)
			argv->precision = ft_strlen("(null)");
		argv->rawstr = ft_substr("(null)", 0, argv->precision);
	}
	else
	{
		if (argv->dot == 0)
			argv->precision = ft_strlen(result);
		argv->rawstr = ft_substr(result, 0, argv->precision);
	}
	if (argv->precision < 0)
		argv->precision = 0;
	str_initial(argv);
	str_fill(argv);
	ft_print_arg(argv);
	if (argv->value != 0)
		free(argv->value);
	if (argv->rawstr != 0)
		free(argv->rawstr);
	ft_cleaner(argv);
}
