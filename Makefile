NAME = fillit
FLAGS = -Wall -Wextra -Werror
FILLIT_SRCS = *.c
LIBFT_SRCS = libft/*.c
OBJS = *.o

$(NAME):
	gcc $(FLAGS) -c $(LIBFT_SRCS)
	ar rc libft.a $(OBJS)
	ranlib libft.a
	gcc $(FLAGS) $(FILLIT_SRCS) -L. -lft -o $(NAME)

all: $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME) libft.a

re: fclean all
