#include "printf.h"

int putstr(void *val)
{
    char *str;
    int size;

    size = 0;
    str = (char *)val;
    while (*str != '\0')
    {
        write(1, &(*str), 1);
        size++;
        str++;
    }
    return (size);
}

int putnbr(void *val)
{
    int nbr;
    int size;
    char *nbr_t;

    nbr = *(int *)val;
    nbr_t = ft_itoa(nbr);
    size = putstr((void *)nbr_t);
    free(nbr_t);
    return (size);
}

int putachar(void *val)
{
    char c;

    c = *(char *)val;
    return (write(1, &c, 1), 1);
}

int putunbr(void *val)
{
    unsigned int nbr;
    int size;
    char *nbr_t;

    nbr = *(unsigned int *)val;
    nbr_t = unsigned_itoa(nbr);
    size = putstr((void *)nbr_t);
    free(nbr_t);
    return (size);
}