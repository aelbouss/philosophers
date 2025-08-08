CC = cc
CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g
NAME = philo

SRCS = philo.c philo_parsing.c philo_parsing1.c philo_tasks.c philo_tasks1.c philo_tasks2.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
