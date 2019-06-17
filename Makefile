# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abenani <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/02 10:22:42 by abenani           #+#    #+#              #
#    Updated: 2019/06/12 18:27:03 by abenani          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COMPILE = gcc -Wall -Wextra -Werror
FILE = src/fillit.c src/functions_a.c src/functions_b.c src/functions_c.c src/functions_d.c
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
