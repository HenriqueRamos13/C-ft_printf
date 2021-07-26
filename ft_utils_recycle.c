#include "ft_printf.h"

void	recycling_long(unsigned long long *n, int *size)
{
	if ((*n) < 0)
	{
		(*n) = -(*n);
		(*size)++;
	}
}

void	recycling_int(unsigned int *n, int *size)
{
	if ((*n) < 0)
	{
		(*n) = -(*n);
		(*size)++;
	}
}