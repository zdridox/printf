#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

char *ft_itoa(int n);
char *ft_strdup(char *src);
size_t ft_strlen(const char *str);
int putnbr(int nbr);
int putunbr(unsigned int nbr);
int putstr(char *str);
char *unsigned_itoa(unsigned int num);
int ft_printf(const char *str, ...);
char *int_to_hex(unsigned long num, int type);
int char_index(char *str, char c);
int printpointer(void *p);