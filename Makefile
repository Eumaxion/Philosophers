NAME = philo

SRCS = main.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Werror -Wextra -pthread

CC = cc

GREEN  := \033[0;32m
RED    := \033[0;31m
YELLOW := \033[1;33m
RESET  := \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME) 
	@echo "$(GREEN)\n COMPILED $(RESET)\n"

clean:
	@rm -f $(OBJS)
	@echo "$(YELLOW) OBJECTS REMOVED $(RESET)"
fclean: clean
	@rm -f $(NAME)
	@echo "$(RED) PROGRAM REMOVED $(RESET)"

re: fclean all 

.Phone: all clean fclean re