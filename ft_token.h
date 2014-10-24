#ifndef FT_TOKEN_H
# define FT_TOKEN_H

# define TOK_UKN 0
# define TOK_NB 1
# define TOK_SUB 2
# define TOK_ADD 3
# define TOK_MUL 4
# define TOK_DIV 5
# define TOK_MOD 6
# define TOK_POW 7
# define TOK_PAROP 8
# define TOK_PARCLOSE 9
# define TOK_END 10
# define TOK_NBNEG (1 << 31)

typedef struct		s_token
{
	char	*content;
	int		type;
}					t_stoken;

typedef t_stoken	*t_token;

t_token				ft_toknew(char *content, int type);

void				ft_tokdel(t_token *tok_p, void(*del)(char **));

void				ft_puttoken(t_token tok);

#endif