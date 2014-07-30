#include "ft_lexer.h"
/*
** Lexer fnctions matrice
*/
t_lexfunc		*g_lexfunc_tab[NB_LEXSTATE - 1][NB_LEXINSTATE] =
{
	// ' ', operateurs, nb, '\0'
	{&skip, &writeop, &stack, &end}, // Start state
	{&flush, &flushwriteop, &stack, &flushend} // Full state
};

t_lexer		ft_lexnew(char *strin)
{
	t_lexer		newlex;

	if (!strin ||
		!(newlex = (t_lexer)ft_memalloc(sizeof(t_slexer))))
		return (NULL);
	if (!(newlex->toklist = ft_ldcdnew()))
	{
		//ft_lexdel(&newlex);
		return (NULL);
	}
	newlex->state = LEX_START;
	newlex->strin = strin;
	return (newlex);
}

void		ft_lexdel(t_lexer *lex_p)
{
	if (!lex_p || !*lex_p)
		return ;
	ft_memdel((void **)lex_p);
}

int		ft_getlexin_ind(char c)
{
	if (c == ' ' || c == '\t')
		return (0);
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '(' || c == ')')
		return (1);
	if (c >= '0' && c <= '9')
		return (2);
	if (c == '\0')
		return (3);
	return (-1);
}

t_ldcd	ft_lexerize(char *strin)
{
	t_lexer		lexer;
	int			error;
	int			lexin_ind;

	if (!(lexer = ft_lexnew(strin)))
			return (NULL);
	//if (ft_lextrim(strin))
	//ft_putstr("Bad chars or numbers separated by space");
	while (lexer->state != LEX_END)
	{
		if (-1 == (lexin_ind = ft_getlexin_ind(*(lexer->strin)))
			|| (error = (*g_lexfunc_tab[lexer->state][lexin_ind])(lexer)))
		{
			ft_putendl_fd((lexin_ind == -1) ? "BAD_CHARS" : "LEX_ERROR", 2);
			//ft_printerror((lexin_ind == -1) ? BAD_CHARS : error);
			return (NULL);
		}
		++lexer->strin;
	}
	return (lexer->toklist);
}
