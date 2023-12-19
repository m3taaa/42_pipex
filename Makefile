NAME = pipex
CC = gcc
SRCS =	src/main.c
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
