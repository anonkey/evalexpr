#include "ft_parser.h"

int		writeout(t_rpnpars pars)
{
	t_token		tok;

	if (!(tok = ft_ldcdpop_front(pars->lstin)))
		return (-1);
	if (pars->sign == '-')
		tok->type |= TOK_NBNEG;
	if (-1 == ft_ldcdpush_back(pars->result, tok, 0))
		return (-2);
	pars->sign = '+';
	pars->state = PARS_NB;
	return (0);
}

int		parsend(t_rpnpars pars)
{
	t_token		tok;
	t_token		tmptok;

	if (!(tok = ft_ldcdpop_front(pars->lstin)))
		return (-1);
	while (ft_ldcdsize(pars->opstack))
	{

		if (!(tmptok = ft_ldcdpop_front(pars->opstack)))
			return (-2);
		if (tmptok->type == TOK_PAROP)
				return (-3);
		if (-1 == ft_ldcdpush_back(pars->result, tmptok, 0))
			return (-3);
	}
	pars->state = PARS_END;
	return (0);
}
