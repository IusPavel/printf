#include "ft_printf.h"

char	*ft_ctoa(int n)
{
	char			*result;
	unsigned char	word;

	word = (unsigned char)n;
	result = (char *)malloc(sizeof(char) * 2);
	if (!result)
		return (0);
	result[0] = word;
	result[1] = '\0';
	return (result);
}
