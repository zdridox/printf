#include "printf.h"

int handle_type(char type, void *val)
{
    int size;

    size = 0;
    if (type == 's')
        size += putstr(val);
    if (type == 'd')
        size += putnbr(&val);
    if (type == 'c')
        size += putachar(&val);
    return (size);
}

int ft_printf(const char *str, ...)
{
    va_list args;
    void *p;
    int size;

    size = 0;
    va_start(args, str);
    while (*str)
    {
        if (*str == '%')
        {
            p = va_arg(args, void *);
            size += handle_type(*(str + 1), p);
            str++;
        }
        else
            size += putachar((void *)str);
        str++;
    }
    return (va_end(args), size);
}

int main()
{
    int size;
    char str[] = "marek";
    int num = 50;
    char c = 'c';

    size = ft_printf("str: %s int: %d char: %c\n", str, num, c);
    putnbr(&size);
    return 0;
}