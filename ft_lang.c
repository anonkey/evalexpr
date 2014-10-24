#include "ft_lang.h"
#include "ft_exec.h"
#include "ft_token.h"
#include <stdlib.h>

t_def			g_dict[NB_LANG_TYPES + 1] =
{
	{"0-9", LANG_NB, 0, 0, NULL},
	{"-", LANG_SUB, 1, LANG_LASSOC, &ft_sub},
	{"+", LANG_ADD, 1, LANG_LASSOC, &ft_add},
	{"*", LANG_MUL, 2, LANG_LASSOC, &ft_mul},
	{"/", LANG_DIV, 2, LANG_LASSOC, &ft_div},
	{"%", LANG_MOD, 2, LANG_LASSOC, &ft_mod},
	{"^", LANG_POW, 3, LANG_RASSOC, &ft_pow},
	{"(", LANG_PAROP, 4, LANG_LASSOC, NULL},
	{")", LANG_PARCLOSE, 4, LANG_LASSOC, NULL},
	{"END", LANG_END, 5, LANG_LASSOC, NULL}
};


t_opfunc	ft_langget_func(int type)
{
	int		i;

	if (type & TOK_NBNEG)
		type |= TOK_NBNEG;
	i = 0;
	while (i < NB_LANG_TYPES)
	{
		if (g_dict[i].type == type)
				return (g_dict[i].func);
		++i;
	}
	return (NULL);
}

int			ft_langget_type(char *str)
{
	int		i;

	i = 0;
	while (i < NB_LANG_TYPES)
	{
		if (!((g_dict[i].desc)[1]))
		{
			if (*str == *(g_dict[i].desc))
				return (g_dict[i].type);
		}
		else
		{
			if (*str >= *(g_dict[i].desc)
				&& *str <= (g_dict[i].desc)[2])
				return (g_dict[i].type);
		}
		++i;
	}
	return (0);
}

t_def		*ft_langget_def(char *str)
{
	int		i;

	i = 0;
	while (i < NB_LANG_TYPES)
	{
		if (!((g_dict[i].desc)[1]))
		{
			if (*str == *(g_dict[i].desc))
				return (g_dict + i);
		}
		else
		{
			if (*str >= *(g_dict[i].desc)
				&& *str <= (g_dict[i].desc)[2])
				return (g_dict + i);
		}
		++i;
	}
	return (NULL);
}
