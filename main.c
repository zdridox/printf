#include "printf.h"

int main()
{
    int size;
    char str[] = "marek";
    int num = 50;
    unsigned int unum = 4294967295;
    char c = 'c';

    size = ft_printf("%%: %% s: %s d: %d c: %c i: %i u: %u x: %x X: %X p: %p\n", str, num, c, num + 5, unum, 255, -255, &num);
    ft_printf("%d", size);
    return 0;
}