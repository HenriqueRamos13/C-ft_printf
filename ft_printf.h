#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "./libft/libft.h"
# define OCTAL "01234567"
# define HEXUPPER "0123456789ABCDEF"
# define HEXLOWER "0123456789abcdef"
# define CCONVERSIONS "cspdiuxX%"

int		ft_printf(const char *str, ...);
int		params_count(const char *str);
int		ft_treat_percent(char c);
int		ft_print_char(int c);
int		ft_print_string(char *str);
int		ft_print_hex(unsigned int num, char *base);
int		ft_print_int(int n);
int		ft_print_uint(int n);
int		ft_treat_pointer(unsigned long long num);
void	recycling_long(unsigned long long *n, int *size);
void	recycling_int(unsigned int *n, int *size);

#endif