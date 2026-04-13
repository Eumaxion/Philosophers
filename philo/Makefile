# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/27 11:11:49 by mlima-si          #+#    #+#              #
#    Updated: 2026/04/13 19:58:51 by mlima-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SCR = main.c utils.c init_args.c monitor.c mutaxes.c simulation.c 

OBJ = $(SCR:.c=.o)

CFLAGS += -Wall -Werror -Wextra

all: $(NAME)

$(NAME) : $(OBJ)
	@cc $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "Compiled"

clean : 
	@rm $(OBJ)
	@echo "Cleaned objs"

fclean : clean
	@rm $(NAME)
	@echo "Cleaned all"

re: fclean all
	@echo "rebuilded"

.PHONY: all clean fclean re