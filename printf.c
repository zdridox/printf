#include "printf.h"

void putstr(char *str)
{
    while (*str != '\0')
    {
        write(1, &(*str), 1);
        str++;
    }
}

void putnbr(int nbr)
{
    char *nbr_t;

    nbr_t = ft_itoa(nbr);
    putstr(nbr_t);
    free(nbr_t);
}

int ft_printf(const char *str, ...)
{
    va_list args;
    char *s;
    int d;
    char c;

    va_start(args, str);
    while (*str)
    {
        if (*str == '%')
        {
            if (*(str + 1) == 's')
            {
                s = va_arg(args, char *);
                putstr(s);
            }
            if (*(str + 1) == 'd')
            {
                d = va_arg(args, int);
                putnbr(d);
            }
            if (*(str + 1) == 'c')
            {
                c = va_arg(args, int);
                write(1, &c, 1);
            }
            str++;
        }
        else
        {
            write(1, &(*str), 1);
        }
        str++;
    }
    va_end(args);
}

int main()
{
    char str[] = "marek";
    int num = 50;
    char c = 'c';

    ft_printf("str: %s int: %d char: %c", str, num, c);
    return 0;
}