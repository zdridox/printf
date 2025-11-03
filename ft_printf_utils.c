/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:16:17 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/03 13:16:18 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(char *src)
{
	int		size;
	int		i;
	char	*dup;

	i = 0;
	size = 0;
	while (src[size] != '\0')
		size++;
	dup = malloc(size + 1);
	if (!dup)
		return (NULL);
	while (src[i] != '\0')
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	char_index(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	hex_string_size(unsigned long num)
{
	int	size;

	size = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= 16;
		size++;
	}
	return (size);
}

char	*int_to_hex(unsigned long num, int type)
{
	char	*str;
	char	*hex_chars;
	int		size;
	int		i;

	if (type == 1)
		hex_chars = ft_strdup("0123456789ABCDEF");
	else
		hex_chars = ft_strdup("0123456789abcdef");
	size = hex_string_size(num);
	i = size - 1;
	str = malloc(size + 1);
	str[size] = '\0';
	if (num == 0)
	{
		str[0] = '0';
		return (free(hex_chars), str);
	}
	while (num > 0)
	{
		str[i] = hex_chars[num % 16];
		num /= 16;
		i--;
	}
	return (free(hex_chars), str);
}
