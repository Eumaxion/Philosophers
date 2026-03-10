NAME		= philo

CC				= cc
CFLAGS			= -Werror -Wextra -Wall -g
CFLAGS_SANITIZE	= -Wall -Wextra -Werror -g -L. -lpthread -g3 -fsanitize=thread -O3 -march=native

INC			=	-I ./

SRC_PATH	=	./
SRC			=	philo.c init.c utils.c simulation.c monitor.c get_set.c \
				fork_ops.c mutexes.c get_set2.c

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