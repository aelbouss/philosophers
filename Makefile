CC=cc
CFLAGS= -Wall -Werror -Wextra
NAME=philosophers

SRCS = philosophers.c

all: $(NAME)
objs = $(src:.c=.o)


clean:
	rm -rf $(objs)
fclean: clean
	rm -rf $(NAME)
re: fclean all

.SECONDARY : $(objs)