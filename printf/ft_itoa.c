#include "ft_printf.h"

static size_t	ft_count(long long int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		n = n * -1;
	if (n == 0)
		len++;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_unusual_case(char *result, long long int n)
{
	if (n == 0)
		result[0] = '0';
	if (n < -9223372036854775807)
	{
		result[0] = '9';
		result[1] = '2';
		result[2] = '2';
		result[3] = '3';
		result[4] = '3';
		result[5] = '7';
		result[6] = '2';
		result[7] = '0';
		result[8] = '3';
		result[9] = '6';
		result[10] = '8';
		result[11] = '5';
		result[12] = '4';
		result[13] = '7';
		result[14] = '7';
		result[15] = '5';
		result[16] = '8';
		result[17] = '0';
		result[18] = '8';
	}
	return (result);
}

char	*ft_itoa(long long int n)
{
	size_t	len;
	char	*result;

	len = ft_count(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len--] = '\0';
	if (n == 0 || n < -9223372036854775807)
		return (ft_unusual_case(result, n));
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		result[len] = (n % 10) + '0';
		n = n / 10;
		len--;
	}
	return (result);
}
