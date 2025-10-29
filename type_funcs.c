#include "printf.h"

int putstr(char *str)
{
    int size;

    size = 0;
    while (*str != '\0')
    {
        write(1, &(*str), 1);
        size++;
        str++;
    }
    return (size);
}

int putnbr(int nbr)
{
    int size;
    char *nbr_t;

    nbr_t = ft_itoa(nbr);
    size = putstr(nbr_t);
    free(nbr_t);
    return (size);
}

int putunbr(unsigned int nbr)
{
    int size;
    char *nbr_t;

    nbr_t = unsigned_itoa(nbr);
    size = putstr(nbr_t);
    free(nbr_t);
    return (size);
}

int printpointer(void *p)
{
    int size;
    char *hex;

    size = putstr("0x");
    size += putstr(hex = int_to_hex((unsigned long)p, 2));
    return (free(hex), size);
}