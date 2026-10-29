CC = gcc

CFLAGS = -Wall -Wextra -g -Iinclude

SRC = src/main.c

OBJ = $(SRC:.c=.o)

NAME = pacman

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
