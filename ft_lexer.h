#ifndef FT_LEXER_H
# define FT_LEXER_H

/*
** lexer define
*/
#define LEX_STACKSIZE_MAX 50
#define NB_LEXINSTATE 4
#define NB_LEXSTATE 3
#define LEX_START 0
#define LEX_NB 1
#define LEX_END 2


#include "libft/headers/libft.h"

typedef struct		s_lexer
{
	char	*strin;
	int		state;
	int		stacksize;
	char	stack[LEX_STACKSIZE_MAX + 1];
	t_ldcd	toklist;
}					t_slexer;

typedef t_slexer	*t_lexer;

typedef int			(t_lexfunc)(t_lexer);

t_lexer		ft_lexnew(char *strin);

void		ft_lexdel(t_lexer *lex_p);

int		ft_getlexin_ind(char c);

t_ldcd	ft_lexerize(char *strin);

int		flushend(t_lexer lex);

int		stack(t_lexer lex);

int		flush(t_lexer lex);

int		flushwriteop(t_lexer lex);

int		end(t_lexer lex);

int		skip(t_lexer lex);

int		writeop(t_lexer lex);

#endif /* !FT_LEXER_H */
