CC = cc
CFLAGS = -Wall -Wextra -Werror 
#CFLAGS = -fsanitize=address 
#CFLAGS = -fsanitize=leak -g 
INCLUDE = -I$(PIPEX_HEADERS) -I$(LIBFT_HEADER)
BONUS_INCLUDE = -I$(BONUS_PIPEX_HEADERS) -I$(LIBFT_HEADER)
LDFLAGS = -L$(LIBFT_DIRECTORY) -lft
SRCS = ./src/main.c\
		./src/exit.c\
		./src/make_absolute_path/make_absolute_path.c\
		./src/make_absolute_path/if_slash_exists_cmd.c\
		./src/processes.c\
		./src/split_space_and_quote/split_space_and_quote.c\
		./src/split_space_and_quote/ft_strsplit.c\
		./src/split_space_and_quote/join_structure.c\
		./src/split_space_and_quote/skip_space_and_join_str.c\
 
BONUS_SRCS = ./src_bonus/main_bonus.c\
		./src_bonus/exit_bonus.c\
		./src_bonus/make_absolute_path/make_absolute_path_bonus.c\
		./src_bonus/make_absolute_path/if_slash_exists_cmd_bonus.c\
		./src_bonus/call_multiple_pipes_func_bonus.c\
		./src_bonus/create_unique_file_name_bonus.c\
		./src_bonus/final_cmd_process_bonus.c\
		./src_bonus/pipex_core_bonus.c\
		./src_bonus/first_cmd_line_list_process/first_cmd_line_list_process_bonus.c\
		./src_bonus/first_cmd_line_list_process/here_doc_process_bonus.c\
		./src_bonus/first_cmd_line_list_process/put_envp_list_bonus.c\
		./src_bonus/split_space_and_quote/split_space_and_quote_bonus.c\
		./src_bonus/split_space_and_quote/ft_strsplit_bonus.c\
		./src_bonus/split_space_and_quote/join_structure_bonus.c\
		./src_bonus/split_space_and_quote/skip_space_and_join_str_bonus.c\

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)
NAME = pipex
BONUS_NAME = pipex_bonus

PIPEX_HEADERS = ./includes/
BONUS_PIPEX_HEADERS = ./includes/

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADER = $(LIBFT_DIRECTORY)

all: libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDE) $(LIBFT) $(OBJS) $(LDFLAGS)  -o $(NAME)

bonus: fclean libft $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_INCLUDE) $(LIBFT) $(BONUS_OBJS) $(LDFLAGS) -o $(BONUS_NAME)

libft:
	make -C $(LIBFT_DIRECTORY)

clean:
	make -C $(LIBFT_DIRECTORY) clean
	rm -f $(OBJS)
	rm -f $(BONUS_OBJS)

fclean: clean
	make -C $(LIBFT_DIRECTORY) fclean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)


re: fclean all

.PHONY: all clean fclean re bonus libft