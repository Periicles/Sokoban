##
## EPITECH PROJECT, 2023
## PSU [WSL: Ubuntu]
## File description:
## Makefile
##

CC = gcc

DIR = src

CFLAGS = -Wall -Wextra

SRC = $(DIR)/mini_printf.c \
	  $(DIR)/my_put_nbr.c \
	  $(DIR)/my_putchar.c \
	  $(DIR)/my_putstr.c \
	  $(DIR)/my_strlen.c

OBJ = $(SRC:.c=.o)

NAME = libmy.a

RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
