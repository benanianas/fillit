# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenani <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/02 10:22:42 by abenani           #+#    #+#              #
#    Updated: 2019/07/26 13:09:18 by abenani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILE = gcc -Wall -Wextra -Werror
FILE = src/main.c src/check_n_save.c src/freeing.c src/tetriminos.c src/tools.c
NAME = fillit
MYLIB = GNL/libft/libft.a
GNL = GNL/get_next_line.c

$(NAME) :
	@cd GNL/libft && Make
	@$(COMPILE) -o $(NAME) $(FILE) $(GNL) $(MYLIB) 

all : $(NAME)

clean :
	@cd GNL/libft && $(MAKE) fclean
fclean : clean
	@rm -rf $(NAME)
re : fclean all
