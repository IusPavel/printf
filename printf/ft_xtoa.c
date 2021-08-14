#include "ft_printf.h"

static size_t	ft_count(unsigned long long int n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		len++;
	while (n > 0)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

char	*ft_xtoa(unsigned long long int n)
{
	size_t					len;
	char					*result;
	unsigned long long int	word;

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
		word = n % 16;
		if (word > 9)
			result[len] = word + 87;
		else
			result[len] = word + '0';
		n = n / 16;
		len--;
	}
	return (result);
}
