#include "ft_parser.h"

int		flushpar(t_rpnpars pars)
{
	t_token		tok;
	t_token		tmptok;

	if (!(tok = ft_ldcdpop_front(pars->lstin)))
		return (-1);
	ft_tokdel(&tok, ft_strdel);
	while (!tok && ft_ldcdsize(pars->opstack))
	{

		if (!(tmptok = ft_ldcdpop_front(pars->opstack)))
			return (-2);
		if (tmptok->type == TOK_PAROP)
			tok = tmptok;
		else
		{
			if (-1 == ft_ldcdpush_back(pars->result, tmptok, 0))
				return (-3);
		}
	}
	if (!tok)
		return (-4);
	ft_tokdel(&tok, ft_strdel);
	pars->state = PARS_PARCLOSE;
	return (0);
}

int		stacksign(t_rpnpars pars)
{
	t_token		tok;

	if (!(tok = ft_ldcdpop_front(pars->lstin)))
		return (-1);
	pars->sign = '-';
	pars->state = PARS_SIGN;
	return (0);
}

int		stackop(t_rpnpars pars)
{
	t_token		tok;
	t_token		optmp;

	if (!(tok = ft_ldcdpop_front(pars->lstin)))
		return (-1);
	if (ft_ldcdsize(pars->opstack)
			&& 0 >= ft_opcmp(pars->opstack->head->content, tok))
	{
		if (!(optmp = ft_ldcdpop_front(pars->opstack)))
			return (-2);
		if (-1 == ft_ldcdpush_back(pars->result, optmp, 0))
			return (-3);
	}
	if (-1 == ft_ldcdpush_front(pars->opstack, tok, 0))
		return (-4);
	pars->state = PARS_OP;
	return (0);
}

int		stackpar(t_rpnpars pars)
{
	t_token		tok;

	if (!(tok = ft_ldcdpop_front(pars->lstin)))
		return (-1);
	if (-1 == ft_ldcdpush_front(pars->opstack, tok, 0))
		return (-4);
	pars->state = PARS_PAROP;
	return (0);
}


