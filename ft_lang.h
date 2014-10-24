#ifndef FT_LANG_H
# define FT_LANG_H
# include "ft_token.h"
# include "ft_exec.h"
# define NB_LANG_TYPES 9
# define LANG_RASSOC 0
# define LANG_LASSOC 1
# define LANG_NB TOK_NB
# define LANG_SUB TOK_SUB
# define LANG_ADD TOK_ADD
# define LANG_MUL TOK_MUL
# define LANG_DIV TOK_DIV
# define LANG_MOD TOK_MOD
# define LANG_POW TOK_POW
# define LANG_PAROP TOK_PAROP
# define LANG_PARCLOSE TOK_PARCLOSE
# define LANG_END NB_LANG_TYPES + 1

typedef struct		s_def
{
	char			*desc;
	int				type;
	int				prior;
	int				assoc;
	t_opfunc		func;
}					t_def;

t_opfunc	ft_langget_func(int type);

int			ft_langget_type(char *str);

t_def		*ft_langget_def(char *str);

#endif /* !FT_LANG_H */
