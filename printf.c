#include "printf.h"

int handle_type(char type, void *val)
{
    int size;

    if (type == 's')
        size = putstr(val);
    if (type == 'd' || type == 'i')
        size = putnbr(&val);
    if (type == 'c')
        size = putachar(&val);
    if (type == 'u')
        size = putunbr(&val);
    if (type == '%')
        size = write(1, "%", 1);
    return (size);
}

int ft_printf(const char *str, ...)
{
    va_list args;
    void *p;
    int size;

    size = 0;
    if (str_validator(str) < 0)
        return (-1);
    va_start(args, str);
    while (*str)
    {
        if (*str == '%')
        {
            if (*(str + 1) != '%')
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
    unsigned int unum = 4294967295;
    char c = 'c';

    size = ft_printf("%%: %% s: %s d: %d c: %c i: %i u: %u\n", str, num, c, num + 5, unum);
    putnbr(&size);
    return 0;
}
