/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 10:57:01 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/03 10:57:03 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

char	*ft_itoa(int n);
char	*ft_strdup(char *src);
size_t	ft_strlen(const char *str);
int		putnbr(int nbr);
int		putunbr(unsigned int nbr);
int		putstr(char *str);
char	*unsigned_itoa(unsigned int num);
int		ft_printf(const char *str, ...);
char	*int_to_hex(unsigned long num, int type);
int		char_index(char *str, char c);
int		printpointer(void *p);
int		puthex(unsigned long num, int type);
