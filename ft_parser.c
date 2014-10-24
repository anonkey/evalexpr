#include "ft_parser.h"
#include "ft_lang.h"
#include "ft_token.h"

t_parsfunc		g_parsfunc_tab[NB_PARS_STATES - 1][NB_PARS_INSTATES] =
{
	{&stacksign, NULL, &writeout, &stackpar, NULL, NULL},
	{&stacksign, NULL, &writeout, &stackpar, NULL, NULL},
	{&stackop, &stackop, NULL, NULL, &flushpar, &parsend},
	{&stacksign, NULL, &writeout, &stackpar, NULL, NULL},
	{NULL, NULL, &writeout, NULL, NULL, NULL},
	{&stackop, &stackop, NULL, NULL, &flushpar, &parsend}
};

int		ft_opcmp(t_token tok1, t_token tok2)
{
	t_def		*def1;
	t_def		*def2;

	if (!(def1 = ft_langget_def(tok1->content))
		|| !(def2 = ft_langget_def(tok2->content)))
		return (-1);
	if (def1->type == LANG_PAROP || def1->type == LANG_PARCLOSE)
		return (4);
	if (def1->prior == def2->prior && def1->assoc == LANG_RASSOC)
		return (1);
	return (def2->prior - def1->prior);
}

int		ft_getparsin_ind(t_rpnpars pars)
{
	t_token		tok;

	tok = pars->lstin->head->content;
	if (tok->type == TOK_SUB)
		return (0);
	if (tok->type >= TOK_ADD && tok->type <= TOK_POW)
		return (1);
	if (tok->type == TOK_NB)
		return (2);
	if (tok->type == TOK_PAROP)
		return (3);
	if (tok->type == TOK_PARCLOSE)
		return (4);
	if (tok->type == TOK_END)
		return (5);
	return (-1);
}

t_rpnpars		ft_rpnparsnew(t_ldcd toklist)
{
	t_rpnpars	newpars;

	if (!toklist || !ft_ldcdsize(toklist)
		|| !(newpars = (t_rpnpars)ft_memalloc(sizeof(t_srpnpars))))
		return (NULL);
	if (!(newpars->result = ft_ldcdnew())
		|| !(newpars->opstack = ft_ldcdnew()))
	{
		//ft_rpnparsdel(&newpars);
		return (NULL);
	}
	newpars->sign = '+';
	newpars->lstin = toklist;
	newpars->state = PARS_START;
	return (newpars);
}

t_ldcd	ft_rpn(t_ldcd toklist)
{
	t_rpnpars	pars;
	int			error;
	int			parsin_ind;

	if (!toklist || !(pars = ft_rpnparsnew(toklist)))
		return (NULL);
	while (pars->state != PARS_END)
	{
		if (-1 == (parsin_ind = ft_getparsin_ind(pars))
			|| !g_parsfunc_tab[pars->state][parsin_ind]
			|| (error = (*g_parsfunc_tab[pars->state][parsin_ind])(pars)))
			return (NULL);
	}
	return (pars->result);
}
