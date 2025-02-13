NAME = libgnl.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.


SRC_DIR := src
SRC :=	get_next_line_bonus.c \
	get_next_line_utils_bonus.c
OBJ = ${SRC:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
