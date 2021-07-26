#include "ft_printf.h"

void	ft_itoab(unsigned int n, char *p, char *base)
{
	int				base_pos;
	int				size;
	unsigned int	copy;
	unsigned int	base_len;

	base_len = ft_strlen(base);
	size = 0;
	recycling_int(&n, &size);
	copy = n;
	while (copy > 0)
	{
		copy /= base_len;
		size++;
	}
	while (n > 0)
	{
		base_pos = n % base_len;
		if (base_pos <= 9)
			p[size - 1] = base[base_pos];
		else
			p[size - 1] = base[base_pos];
		size--;
		n = n / base_len;
	}
}

int	ft_print_string(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_print_hex(unsigned int num, char *base)
{
	char	*p;
	int		len;

	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	p = ft_calloc(33, sizeof(char));
	ft_itoab((unsigned int)num, p, base);
	ft_print_string(p);
	len = ft_strlen(p);
	free(p);
	p = NULL;
	return (len);
}

void	ft_itoap(unsigned long long n, char *p, char *base)
{
	int					base_pos;
	int					size;
	unsigned long long	copy;
	unsigned long long	base_len;

	base_len = ft_strlen(base);
	size = 0;
	recycling_long(&n, &size);
	copy = n;
	while (copy > 0)
	{
		copy /= base_len;
		size++;
	}
	while (n > 0)
	{
		base_pos = n % base_len;
		if (base_pos <= 9)
			p[size - 1] = base[base_pos];
		else
			p[size - 1] = base[base_pos];
		size--;
		n = n / base_len;
	}
}

int	ft_treat_pointer(unsigned long long num)
{
	char	*p;
	int		len;

	ft_putstr_fd("0x", 1);
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return (3);
	}
	p = ft_calloc(33, sizeof(char));
	ft_itoap((unsigned long long)num, p, HEXLOWER);
	ft_print_string(p);
	len = ft_strlen(p);
	free(p);
	p = NULL;
	return (len + 2);
}
