CC = clang
CFLAGS = -Wall -Wextra -Werror
NAME = eexpr
SRC = ft_lang.c ft_lexer.c ft_lexnb.c ft_lexopspace.c ft_parsefuncstack.c ft_parser.c  ft_parsfuncresult.c  ft_token.c  main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

gcc: $(OBJ)
gcc $(CFLAGS) $(OBJ) -o $(NAME)

$(NAME): $(OBJ)
$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
$(CC) -o $@ -c $< $(CFLAGS)

clean:
rm -rf $(OBJ)

fclean: clean
rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re