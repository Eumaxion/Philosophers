# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlima-si <mlima-si@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/27 11:11:49 by mlima-si          #+#    #+#              #
#    Updated: 2026/04/26 13:13:14 by mlima-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SCR = main.c utils.c init_args.c monitor.c forks_mutex.c philo_routine.c utils2.c

OBJ = $(SCR:.c=.o)

CFLAGS += -Wall -Werror -Wextra

GREEN  := \033[0;32m
RED    := \033[0;31m
YELLOW := \033[1;33m
RESET  := \033[0m

all: $(NAME)

$(NAME) : $(OBJ)
	@cc $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)\n COMPILATION DONE \n$(RESET) "

.c.o:
	@$(CC) $(FLAGS) -c  $< -o ${<:.c=.o}

clean : 
	@rm -f $(OBJ)
	@echo "$(YELLOW)\n OBJECTS REMOVED $(RESET) \n"

fclean : clean
	@rm -f $(NAME)
	@echo "$(RED)\n EXECUTABLES REMOVED $(RESET) \n"

re: fclean all
	@echo "$(GREEN)\n REBUILDED \n$(RESET) "

.PHONY: all clean fclean re