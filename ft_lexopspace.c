#include "ft_lexer.h"
#include "ft_token.h"
#include "ft_lang.h"

int		end(t_lexer lex)
{
	t_token		tok;

	if (!(tok = ft_toknew("END", TOK_END))
		|| -1 == ft_ldcdpush_back(lex->toklist, tok, 0))
		return (-1);
	lex->state = LEX_END;
	return (0);
}

int		skip(t_lexer lex)
{
	lex->state = LEX_START;
	return (0);
}

int		writeop(t_lexer lex)
{
	t_token		tok;
	t_def		*def;

	if (!(def = ft_langget_def(lex->strin)))
		return (-2);
	if (!(tok = ft_toknew(def->desc, def->type))
		|| -1 == ft_ldcdpush_back(lex->toklist, tok, 0))
		return (-1);
	lex->state = LEX_START;
	return (0);
}
