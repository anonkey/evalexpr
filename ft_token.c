#include <stdlib.h>
#include "ft_token.h"
#include "libft/headers/libft.h"

t_token				ft_toknew(char *content, int type)
{
	char	*cpy;
	t_token	newtok;

	if (!content
		|| !(cpy = ft_strdup(content)))
		return (NULL);
	if (!(newtok = (t_token)ft_memalloc(sizeof(t_stoken))))
	{
		free(cpy);
		return (NULL);
	}
	newtok->content = cpy;
	newtok->type = type;
	return (newtok);
}

void				ft_puttoken(t_token tok)
{
	if (!tok)
		ft_putendl("NULL TOKEN");
	else
	{
		ft_putstr("Token : type:");
		ft_putnbr(tok->type);
		ft_putstr(" content :");
		ft_putendl(tok->content);
	}
}

void				ft_tokdel(t_token *tok_p, void(*del)(char **))
{
	if (!tok_p || !*tok_p)
		return ;
	if (del)
		(*del)(&((*tok_p)->content));
	ft_memdel((void **)tok_p);
}
