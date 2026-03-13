# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/13 14:44:15 by mlima-si          #+#    #+#              #
#    Updated: 2026/03/13 14:44:16 by mlima-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

CC				= cc
CFLAGS			= -Werror -Wextra -Wall -g
CFLAGS_SANITIZE	= -Wall -Wextra -Werror -g -L. -lpthread -g3 -fsanitize=thread -O3 -march=native

INC			=	-I ./

SRC_PATH	=	./
SRC			=	philo.c init.c helpers.c simulation.c monitor_loop.c acessors.c \
				fork_utils.c mutex.c acessors_2.c

OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	@echo "Compiling philo..."
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INC)
	@echo "✅ Philo compiled!!!"

clean:
	@echo "Removing .o object files..."
	rm -rf $(OBJ_PATH)

fclean: clean
	@echo "Removing binaries..."
	rm -f $(NAME)

re: fclean all

sanitize: $(OBJS)
	@echo "Compiling philo with sanitizers..."
	$(CC) $(CFLAGS_SANITIZE) -o $(NAME) $(OBJS) $(INC)
	@echo "✅ Philo compiled with sanitize flags!!!"

.PHONY: all re clean fclean