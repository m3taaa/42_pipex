NAME = pipex
CC = gcc
SRCS =	src/main.c\
		src/check_file.c\
		src/utils.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@echo "pipex create"

clean:
	@rm -f $(OBJS)
	@echo "delete file *.o"

fclean: clean
	@rm $(NAME)
	@echo "delete pipex"

re: fclean all

.PHONY: all clean fclean re
