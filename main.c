#include "libft/headers/libft.h"
#include "ft_lexer.h"
#include "ft_parser.h"
#include "ft_lang.h"
#include "ft_token.h"

/*
** exec define
*/
#define EXPR_NB 0
#define OP_ADDSUB 1
#define OP_MULDIVMOD 2
#define OP_POW 3



int		ft_exectoken(t_token tok, t_ldcd toklist, int *status)
{
	t_token		tmptok;
	t_opfunc	func;
	int			op1;
	int			op2;

	if (*status || !toklist)
		return (0);
	if (tok->type == LANG_NB || tok->type == (TOK_NBNEG | LANG_NB))
		return (tok->type == LANG_NB ? ft_atoi(tok->content) : 0 - ft_atoi(tok->content));
	if (!(tmptok = ft_ldcdpop_back(toklist)))
		return (*status = -1, 0);
	op1 = ft_exectoken(tmptok, toklist, status);
	if (tok->type != LANG_END)
	{
		if (!(tmptok = ft_ldcdpop_back(toklist)))
			return (*status = -2, 0);
		op2 = ft_exectoken(tmptok, toklist, status);
		func = ft_langget_func(tok->type);
		return ((*func)(op1, op2, status));
	}
	return (op1);
}

int			ft_calcexec(t_ldcd toklist, int *result)
{
	t_token		endtok;
	int			error;

	error = 0;
	if (!toklist || !(endtok = ft_ldcdpop_back(toklist)))
		return (-1);
	*result = ft_exectoken(endtok, toklist, &error);
	return (error);
}

int		ft_evalexpr(char *expr)
{
	int		result;
	t_ldcd	toklist;
	t_ldcd	rpnlist;
	//t_token	tok;

	if (!(toklist = ft_lexerize(expr)))
		return (1);
	if (!(rpnlist = ft_rpn(toklist)))
		return (ft_putstr("RPN ERROR\n"), 2);
//	while ((tok = ft_ldcdpop_front(rpnlist)))
//		ft_puttoken(tok);
	if (!ft_calcexec(rpnlist, &result))
		return (ft_putnbr(result), ft_putstr("\n"), 0);
	else
		return (3);
}

int		main(int argc, char **argv)
{
	if (argc < 2)
	return (0);
	if (ft_evalexpr(argv[1]))
		ft_putstr("error\n");
	return (0);
}
