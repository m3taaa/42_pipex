NAME = pipex
CC = gcc
SRCS =	src/main.c\
		src/check_file.c\
		src/utils.c\
		src/init.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Werror -Wall -Wextra
INCLUDES = libft/libft_and_more.a

all: $(NAME)

$(NAME): $(OBJS)
	@make -C libft/ > /dev/null 2>&1
	@$(CC) $(OBJS) $(INCLUDES) -o $(NAME)
	@echo "Pipex Compiled!"

clean:
	@make -C libft/ clean > /dev/null 2>&1
	@rm -f $(OBJS)
	@echo "delete file *.o"

fclean: clean
	@make -C libft/ fclean > /dev/null 2>&1
	@rm $(NAME)
	@echo "delete pipex"

re: fclean all

.PHONY: all clean fclean re
