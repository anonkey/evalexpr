# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tseguier <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/07/31 10:23:26 by tseguier          #+#    #+#              #
#    Updated: 2014/07/31 10:23:34 by tseguier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


ifeq ($(GCC), 1)
	CC = gcc
else
	CC = clang
endif
ifeq ($(DEBUG), 1)
	CFLAGS = -Wall -Wextra -Werror -ggdb3
else
	CFLAGS = -Wall -Wextra -Werror
endif
NAME = evalexpr
INCDIR = ./libft/headers
LIBDIR = ./libft/
LIBNAME = libft
LIB = -lft
SRC = ft_exec.c \
ft_lang.c \
ft_lexer.c \
ft_lexnb.c \
ft_lexopspace.c \
ft_parsefuncstack.c \
ft_parser.c \
ft_parsfuncresult.c \
ft_token.c \
main.c
OBJ = $(SRC:.c=.o)

all: $(LIBNAME) $(NAME)

$(LIBNAME):
	make -C $(LIBDIR)

$(LIBNAME)_fclean:
	make -C $(LIBDIR) fclean

gcc: $(OBJ)
	gcc $(CFLAGS) $(OBJ) -o $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -L$(LIBDIR) $(LIB) $(OBJ) -o $(NAME) -I $(INCDIR)
%.o: %.c
	$(CC) -I$(LIBDIR) $(CFLAGS) -c $< -o $@ -I $(INCDIR)

clean:
	rm -rf $(OBJ)

fclean: $(LIBNAME)_fclean clean
	rm -rf $(NAME)

re: $(LIBNAME)_fclean fclean all

.PHONY: $(LIBNAME) $(LIBNAME)_fclean clean fclean all re