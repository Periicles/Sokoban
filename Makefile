##
## EPITECH PROJECT, 2022
## delivery
## File description:
## Makefile
##

CC = cc

DIR = src

CPPFLAGS = -I./include/

LDFLAGS = -L./lib -lmy

CFLAGS = -Wall -Wextra

LDLIBS = -lncurses

SRC = $(DIR)/check_errors.c \
	  $(DIR)/help.c \
	  $(DIR)/main.c \
	  $(DIR)/maps.c \
	  $(DIR)/move_player.c \
	  $(DIR)/movement_player.c \
	  $(DIR)/moves.c \
	  $(DIR)/player.c \
	  $(DIR)/win_lose.c \
	  $(DIR)/box_n_holes.c \
	  $(DIR)/map_errors.c

OBJ = $(SRC:.c=.o)

NAME = my_sokoban

RM = rm -f

all: make_libs $(NAME)

$(NAME): lib/libmy.a $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDLIBS) $(LDFLAGS)

make_libs:
	make -C lib

clean:
	make -C lib clean
	$(RM) $(OBJ)

fclean: clean
	make -C lib fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all make_libs clean fclean re
