#include "ft_lexer.h"
#include "ft_token.h"

int		flushend(t_lexer lex)
{
	return (flush(lex) + end(lex));
}


int		stack(t_lexer lex)
{
	if (lex->stacksize >= LEX_STACKSIZE_MAX)
		return (-1);
	lex->stack[lex->stacksize] = *(lex->strin);
	++lex->stacksize;
	lex->stack[lex->stacksize] = '\0';
	lex->state = LEX_NB;
	return (0);
}

int		flush(t_lexer lex)
{
	t_token		tok;

	lex->stacksize = 0;
	if (!(tok = ft_toknew(lex->stack, TOK_NB))
		|| -1 == ft_ldcdpush_back(lex->toklist, tok, 0))
		return (-1);
	lex->state = LEX_START;
	return (0);
}

int		flushwriteop(t_lexer lex)
{
	return (flush(lex) + writeop(lex));
}
