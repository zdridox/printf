#include "printf.h"

// #include <stdio.h>

static int digit_sum(int n)
{
	int i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char *rev_str(char *str)
{
	int i;
	int size;
	char temp;

	size = ft_strlen(str);
	i = 0;
	while (i < size / 2)
	{
		temp = str[i];
		str[i] = str[size - i - 1];
		str[size - i - 1] = temp;
		i++;
	}
	return (str);
}

char *ft_itoa(int n)
{
	char *result;
	int i;
	int size;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	size = digit_sum(n);
	result = malloc(size + 1);
	if (!result)
		return (NULL);
	if (n < 0)
	{
		result[size - 1] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		result[i] = n % 10 + 48;
		n /= 10;
		i++;
	}
	return (result[size] = '\0', rev_str(result));
}

/*
int	main(void) {
	printf("digit sum of 6789421: %d\n", digit_sum(6789421));
	printf("digit sum of -6789421: %d\n", digit_sum(-6789421));
	printf("digit sum of 0: %d\n", digit_sum(0));
	printf("digit sum of 1: %d\n", digit_sum(1));
	char str1[] = "dupa";
	char str2[] = "ptaka";
	printf("reversed str 'dupa': %s\n", rev_str(str1));
	printf("reversed str 'ptaka': %s\n", rev_str(str2));
	printf("itoa 5684213: %s\n", ft_itoa(5684213));
	printf("itoa -5684213: %s\n", ft_itoa(-5684213));
	printf("itoa 500: %s\n", ft_itoa(500));
	printf("itoa -500: %s\n", ft_itoa(-500));
	printf("itoa 2147483647: %s\n", ft_itoa(2147483647));
	printf("itoa -2147483648: %s\n", ft_itoa(-2147483648));
	printf("itoa 0: %s\n", ft_itoa(0));
	return (0);
}
*/