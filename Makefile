CC=cc
CFLAGS=  -Wall -Werror -Wextra
NAME= philosophers

SRCS = philo.c philo_parsing.c philo_parsing1.c

 OBJS=$(SRCS:.c=.o)

NAME: $(objs)
	cc $(CFLAGS) $(OBJS) -o $(NAME)
%.o : %.c
	cc $(FLAGS) -c $< -o $@ 
clean:
	rm -rf $(objs)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.SECONDARY : $(objs)