#include "printf.h"

char *ft_strdup(char *src)
{
    int size;
    int i;
    char *dup;

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

size_t ft_strlen(const char *str)
{
    size_t i;

    if (!str)
        return (0);
    i = 0;
    while (str[i])
        i++;
    return (i);
}

int char_index(char *str, char c)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        if (str[i] == c)
            return (i);
        i++;
    }
    return (-1);
}

int hexStringSize(unsigned long num)
{
    int size = 0;
    if (num == 0)
        return 1;
    while (num > 0)
    {
        num /= 16;
        size++;
    }
    return (size);
}

char *int_to_hex(unsigned long num, int type)
{
    char *str;
    char *hexChars;
    int size;
    int i;

    if (type == 1)
        hexChars = ft_strdup("0123456789ABCDEF");
    else
        hexChars = ft_strdup("0123456789abcdef");
    size = hexStringSize(num);
    i = size - 1;
    str = malloc(size + 1);
    str[size] = '\0';
    if (num == 0)
    {
        str[0] = '0';
        return (free(hexChars), str);
    }
    while (num > 0)
    {
        str[i] = hexChars[num % 16];
        num /= 16;
        i--;
    }
    return (free(hexChars), str);
}