#ifndef FT_EXEC_H
# define FT_EXEC_H

typedef int		(*t_opfunc)(int, int, int *);

int				ft_add(int a, int b, int *status);

int				ft_sub(int a, int b, int *status);

int				ft_mul(int a, int b, int *status);

int				ft_div(int a, int b, int *status);

int				ft_mod(int a, int b, int *status);

#endif /* !FT_EXEC_H */
