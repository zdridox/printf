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

int str_validator(const char *str)
{
    int str_size;
    char *valid_types;
    int i;

    i = 0;
    valid_types = ft_strdup("cspdiuxX%");
    str_size = ft_strlen(str);
    while (str[i] != '\0')
    {
        if (str[i] == '%' && str[i - 1] != '%' && i == str_size - 1)
            return (free(valid_types), -1);
        if (str[i] == '%' && char_index(valid_types, str[i + 1]) == -1 && str[i - 1] != '%')
            return (free(valid_types), -1);
        i++;
    }
    return (free(valid_types), 0);
}