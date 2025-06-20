SRC = $(wildcard *.c)
OBJ = $(SRC:%.c=%.o)
INCLUDE = -I /
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

all: $(NAME)


$(NAME): $(OBJ)
	cc -o $@ $?

%.o: %.c
	cc $(CFLAGS) $(INCLUDE) -c $?

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re