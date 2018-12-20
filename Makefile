NAME = fillit
FLAGS = -Wall -Wextra -Werror
SRC = libft/libft.a
SRCS = *.c

$(NAME):
	gcc $(FLAGS) $(SRC) $(SRCS) -o $(NAME)

all: $(NAME)

clean:
	/bin/rm -f *.o
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
