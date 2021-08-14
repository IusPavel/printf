#include "ft_printf.h"

static size_t	ft_count(unsigned long long int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_utoa(unsigned long long int n)
{
	size_t	len;
	char	*result;

	len = ft_count(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len--] = '\0';
	if (n == 0)
	{
		result[0] = '0';
		return (result);
	}
	while (n > 0)
	{
		result[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (result);
}
