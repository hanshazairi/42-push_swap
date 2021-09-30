M_SOURCES = push_swap.c libft_utils.c validate.c instructions.c sort.c sort_utils.c sort_big_utils.c
B_SOURCES = checker.c libft_utils.c validate.c instructions.c sort_utils.c
M_OBJECTS = $(M_SOURCES:.c=.o)
B_OBJECTS = $(B_SOURCES:.c=.o)

all: push_swap checker

push_swap: $(M_OBJECTS) libft
	gcc -o $@ $(M_OBJECTS) -Llibft -lft

checker: $(B_OBJECTS) libft
	gcc -o $@ $(B_OBJECTS) -Llibft -lft

%.o: %.c
	gcc -c -Wall -Wextra -Werror $?

libft:
	make bonus -C libft

clean:
	rm -f $(M_OBJECTS) $(B_OBJECTS)
	make -C libft clean

fclean: clean
	rm -f push_swap checker libft/libft.a

re: fclean all

.PHONY: all libft clean fclean re
