#include "ft_printf.h"

int	def_type(const char **str, va_list args)
{
	(*str)++;
	if (**str == 'c')
		return (ft_print_char(va_arg(args, int)));
	else if (**str == 's')
		return (ft_print_string(va_arg(args, char *)));
	else if (**str == 'x')
		return (ft_print_hex(va_arg(args, unsigned long long), HEXLOWER));
	else if (**str == 'X')
		return (ft_print_hex(va_arg(args, unsigned long long), HEXUPPER));
	else if (**str == 'd' || **str == 'i')
		return (ft_print_int(va_arg(args, int)));
	else if (**str == 'u')
		return (ft_print_uint((int)va_arg(args, int)));
	else if (**str == 'p')
		return (ft_treat_pointer(va_arg(args, unsigned long long)));
	else if (**str == '%')
		return (ft_treat_percent('%'));
	return (0);
}

int	crossing(const char **str, va_list args, int n_params)
{
	int	count;

	count = 0;
	while (n_params-- > 0)
	{
		while (**str != '\0')
		{
			if (**str == '%')
				count += def_type(str, args);
			else
			{
				count++;
				write(1, &(**str), 1);
			}
			(*str)++;
		}
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		num_param;
	int		to_return;

	to_return = 0;
	num_param = params_count(str);
	if (num_param <= 0)
	{
		ft_putstr_fd((char *)str, 1);
		return (ft_strlen(str));
	}
	va_start(args, str);
	to_return += crossing(&str, args, num_param);
	va_end(args);
	return (to_return);
}
