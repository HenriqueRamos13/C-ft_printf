#include "ft_printf.h"

int	params_count(const char *str)
{
	int	num_param;
	int	count;

	count = -1;
	num_param = 0;
	while (str[++count] != '\0')
		if (str[count] == '%' && ft_strchr(CCONVERSIONS, str[count + 1]))
			num_param++;
	return (num_param);
}

int	ft_print_int(int n)
{
	char	*num;
	int		len;

	num = ft_itoa(n);
	ft_print_string(num);
	len = ft_strlen(num);
	free(num);
	num = NULL;
	return (len);
}

int	ft_print_char(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_treat_percent(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}
