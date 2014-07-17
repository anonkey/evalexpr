
#define EXPR_NB 0
#define OP_ADDSUB 1
#define OP_MULDIV 2
#define OP_POW 3

typedef void -(-t_opfunc)(void *, void *);

typedef struct	    s_def
{
    char    *desc;
    int	    type;
    t_opfunc	func;
}		    t_def;

typedef struct	    s_tok
{
    char    *content;
    t_def   *def;
}		    t_tok;


typedef struct	    s_calc
{
    t_ldcd	opstack;
    t_ldcd	result;
    char	*strin;
    long long	nbact;
}		    t_scalc;

int	ft_evalexpr(char *expr)
{
    
}

int	main(int argc, char **argv)
{
    if (argc < 2)
	return (0);
   ft_evalexpr(argv[1]);
   return (0);
}
