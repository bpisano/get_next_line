# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: bpisano <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/11/29 17:54:11 by bpisano      #+#   ##    ##    #+#        #
#    Updated: 2017/11/30 12:45:40 by bpisano     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME = next

SRC = ./get_next_line.c			\
	  ./main.c					\

OBJECTS = $(SRC:.c=.o)

LIB = libft.a

HEADS = ./includes

FLAGS = -Wall -Werror -Wextra

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
END = \033[0m

all: $(NAME)

$(LIB):
	@(cd libft/ && make)

$(NAME): $(LIB) $(OBJECTS)
	@gcc -o $(NAME) $(OBJECTS) libft/$(LIB)

%.o : %.c
	@gcc $(FLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJECTS)
	@(cd libft/ && make clean)

fclean: clean
	@rm -rf $(NAME)
	@(cd libft/ && make fclean)

re: fclean all
	@echo "\n\t$(GREEN)All the process is ok$(END)\n"
	@(cd libft/ && make re)

