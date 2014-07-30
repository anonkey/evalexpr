#ifndef FT_PARSER_H
# include "libft/headers/libft.h"
# include "ft_token.h"

# define FT_PARSER_H
# define NB_PARS_STATES 7
# define NB_PARS_INSTATES 6
# define PARS_START 0
# define PARS_PAROP 1
# define PARS_NB 2
# define PARS_OP 3
# define PARS_SIGN 4
# define PARS_PARCLOSE 5
# define PARS_END 6

typedef struct		s_rpnpars
{
	t_ldcd		opstack;
	t_ldcd		result;
	t_ldcd		lstin;
	long long	nbact;
	char		sign;
	int			state;
}					t_srpnpars;

typedef t_srpnpars	*t_rpnpars;

typedef int			(*t_parsfunc)(t_rpnpars);

int					ft_opcmp(t_token tok1, t_token tok2);

int					ft_getparsin_ind(t_rpnpars pars);

t_rpnpars			ft_rpnparsnew(t_ldcd toklist);

t_ldcd				ft_rpn(t_ldcd toklist);

int					stackop(t_rpnpars pars);

int					stackpar(t_rpnpars pars);

int					stacksign(t_rpnpars pars);

int					flushpar(t_rpnpars pars);

int		writeout(t_rpnpars pars);

int		parsend(t_rpnpars pars);

#endif /* !FT_PARSER_H */
