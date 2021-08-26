NAME = push_swap
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) libft
	gcc -o $@ $(OBJECTS) -Llibft -lft

%.o: %.c
	gcc -c -Wall -Wextra -Werror $?

libft:
	make -C libft

clean:
	rm -f $(OBJECTS)
	make -C libft clean

fclean: clean
	rm -f $(NAME) libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re
