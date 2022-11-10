CC = cc
CFLAGS = -Wall -Wextra -Werror 
#CFLAGS = -fsanitize=address
INCLUDE = -I$(PUSH_HEADERS) -I$(LIBFT_HEADER) -I$(PRINT_HEADER)
LDFLAGS = -L$(LIBFT_DIRECTORY) -lft -L$(PRINT_DIRECTORY)
SRCS = ./src/main.c\
		./src/quick_sort.c\
		./src/coordinate_compression.c\
		./src/make_a_b_lst.c\
		./src/arg_less_than_6.c\
		./src/ft_push_swap.c\
		./src/operations/push.c\
		./src/operations/rotation.c\
		./src/operations/reverse_rotation.c\
		./src/operations/swap.c\
		./src/a_lst_group_quantity_less_than_6.c\
		./src/find_min_max.c\
		./src/b_lst_sort_of_less_than_6.c\

OBJS = $(SRCS:.c=.o)
NAME = push_swap

PUSH_HEADERS = ./includes/

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADER = $(LIBFT_DIRECTORY)

PRINT = $(PRINT_DIRECTORY)libftprintf.a
PRINT_DIRECTORY = ./printf/
PRINT_HEADER = $(PRINT_DIRECTORY)

all: libft print $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS) $(LDFLAGS) $(PRINT) $(LIBFT) -o $(NAME)

libft:
	make -C $(LIBFT_DIRECTORY)

print:
	make -C $(PRINT_DIRECTORY)

clean:
	make -C $(LIBFT_DIRECTORY) clean
	make -C $(PRINT_DIRECTORY) clean
	rm -f $(OBJS)

fclean: clean
	make -C $(LIBFT_DIRECTORY) fclean
	make -C $(PRINT_DIRECTORY) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus libft print