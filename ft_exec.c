#include "ft_exec.h"
#include "libft.h"

int				ft_add(int a, int b, int *status)
{
	if (*status)
		return (0);
	return (b + a);
}

int				ft_sub(int a, int b, int *status)
{
	if (*status)
		return (0);
	return (b - a);
}

int				ft_mul(int a, int b, int *status)
{
	if (*status)
		return (0);
	return (b * a);
}

int				ft_div(int a, int b, int *status)
{
	if (a == 0)
		*status = -3;
	if (*status)
		return (0);
	return (b / a);
}

int				ft_mod(int a, int b, int *status)
{
	if (a == 0)
		*status = -3;
	if (*status)
		return (0);
	return (b % a);
}

int				ft_pow(int a, int b, int *status)
{
	int		res;
	int		sign;
	int		i;

	sign = (b >= 0) ? 0 : 1;
	b = b >= 0 ? b : 0 - b;
	i = 0;
	if (a < 0)
		*status = -1;
	res = b;
	while (a - i++ > 1)
	{
		res *= b;
		if (res < 0)
			*status = -2;
	}
	if (*status)
		return (0);
	if (sign && a % 2)
		return (0 - res);
	else
		return (res);
}
