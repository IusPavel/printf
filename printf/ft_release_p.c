#include "ft_printf.h"

static void	str_fill(t_list *argv)
{
	size_t	len;
	size_t	i;
	size_t	k;
	int		sign;
	int		q;

	k = 0;
	i = 0;
	q = 0;
	sign = ft_strlen(argv->sign);
	len = ft_strlen(argv->rawstr);
	if (len < (size_t)argv->width && argv->flag_zero == 1)
		len = argv->width - sign;
	if (len < (size_t)argv->precision)
		len = argv->precision;
	if (argv->flag_minus == 0)
		i = ft_strlen(argv->value) - len - sign;
	while (sign--)
		argv->value[i++] = argv->sign[k++];
	if (len > ft_strlen(argv->rawstr))
		while ((len-- - ft_strlen(argv->rawstr)) > 0)
			argv->value[i++] = '0';
	while (argv->rawstr[q])
		argv->value[i++] = argv->rawstr[q++];
}

static void	str_initial(t_list *argv)
{
	size_t	sign;
	char	init;
	size_t	i;
	size_t	len;

	i = 0;
	sign = ft_strlen(argv->sign);
	len = ft_strlen(argv->rawstr);
	if (len + sign < (size_t)argv->width)
		len = argv->width - sign;
	if (len < (size_t)argv->precision)
		len = argv->precision;
	argv->value = (char *)malloc(sizeof(char) * (len + sign + 1));
	argv->value[len + sign] = '\0';
	init = ' ';
	if (argv->flag_zero == 1)
		init = '0';
	while (i < len + sign)
		argv->value[i++] = init;
	argv->value_len = ft_strlen(argv->value);
}

void	ft_release_p(t_list *argv, unsigned long long int result)
{
	argv->sign = "0x";
	argv->rawstr = ft_ptoa(result);
	if (argv->dot == 1 && argv->precision == 0
		&& !ft_strcmp(argv->rawstr, "0"))
		argv->rawstr[0] = '\0';
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
