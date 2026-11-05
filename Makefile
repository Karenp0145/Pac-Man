CC = gcc

CFLAGS = -Wall -Wextra -g -Iinclude -I$(RAYLIB_DIR)

# raylib 6.2 is downloaded (if the raylib/ folder is missing)
# and compiled automatically: nothing to install.
RAYLIB_VERSION = 6.2
RAYLIB_DIR = raylib/src
RAYLIB_LIB = $(RAYLIB_DIR)/libraylib.a

# System libraries needed by raylib, depending on the OS
ifeq ($(OS),Windows_NT)
    SYSLIBS = -lopengl32 -lgdi32 -lwinmm
else ifeq ($(shell uname -s),Darwin)
    SYSLIBS = -framework OpenGL -framework Cocoa -framework IOKit -framework CoreAudio -framework CoreVideo -framework QuartzCore
else
    SYSLIBS = -lGL -lm -lpthread -ldl -lrt -lX11
endif

SRC = src/main.c \
      src/map.c \
      src/ghost.c \
	  src/player.c

OBJ = $(SRC:.c=.o)

NAME = pacman

all: $(NAME)

# Download raylib once (only if the raylib/ folder does not exist yet)
$(RAYLIB_DIR)/raylib.h:
	git clone --depth 1 --branch $(RAYLIB_VERSION) https://github.com/raysan5/raylib.git raylib-tmp
	mkdir -p raylib
	cp -R raylib-tmp/src raylib/src
	cp raylib-tmp/LICENSE raylib/LICENSE
	rm -rf raylib-tmp

# Build raylib once (only if libraylib.a does not exist yet)
$(RAYLIB_LIB): $(RAYLIB_DIR)/raylib.h
	$(MAKE) -C $(RAYLIB_DIR) PLATFORM=PLATFORM_DESKTOP

# The game files need raylib.h, so raylib must be downloaded first
$(OBJ): | $(RAYLIB_DIR)/raylib.h

$(NAME): $(RAYLIB_LIB) $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(RAYLIB_LIB) $(SYSLIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(NAME).exe
	$(MAKE) -C $(RAYLIB_DIR) clean

re: fclean all

.PHONY: all clean fclean re
