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