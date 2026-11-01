CC = gcc

CFLAGS = -Wall -Wextra -g -Iinclude
LDFLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm

SRC = src/main.c \
src/map.c

OBJ = $(SRC:.c=.o)

NAME = pacman

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
