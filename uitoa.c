#include "printf.h"

static int digit_sum(unsigned int n)
{
    int i;

    i = 0;
    if (n == 0)
        return (1);
    while (n > 0)
    {
        i++;
        n /= 10;
    }
    return (i);
}

char *unsigned_itoa(unsigned int num)
{
    char *str;
    int d_sum;
    int i;

    d_sum = digit_sum(num);
    str = malloc(d_sum + 1);
    i = d_sum - 1;
    while (i != -1)
    {
        str[i] = num % 10 + 48;
        num /= 10;
        i--;
    }
    str[d_sum] = '\0';
    return (str);
}