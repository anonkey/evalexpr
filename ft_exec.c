#include "ft_exec.h"

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
