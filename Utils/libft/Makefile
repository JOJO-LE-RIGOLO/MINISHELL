# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 16:48:36 by jtudela           #+#    #+#              #
#    Updated: 2024/11/08 13:04:27 by jotudela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### ARGUMENTS

NAME		= libft.a
CFLAGS		= -Wall -Wextra -Werror
CC		= cc
BONUS_FLAG	= .bonus_compiled

###################################################
### COLORS

RESET = \033[0m
BOLD = \033[1m
RED = \033[91m
GREEN = \033[92m
YELLOW = \033[33m
ORANGE = \033[93m

###################################################
### SOURCES

# MANDATORY PART

SRC_FILES	= ft_atoi \
		ft_bzero \
		ft_calloc \
		ft_isalnum \
		ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_isprint \
		ft_itoa \
		ft_memchr \
		ft_memcmp \
		ft_memcpy \
		ft_memmove \
		ft_memset \
		ft_putchar_fd \
		ft_putendl_fd \
		ft_putnbr_fd \
		ft_putstr_fd \
		ft_split \
		ft_strchr \
		ft_strdup \
		ft_striteri \
		ft_strjoin \
		ft_strlcat \
		ft_strlcpy \
		ft_strlen \
		ft_strmapi \
		ft_strncmp \
		ft_strnstr \
		ft_strrchr \
		ft_strtrim \
		ft_substr \
		ft_tolower \
		ft_toupper

OBJ_FILES	= $(addsuffix .o, $(SRC_FILES))

# BONUS PART

SRC_FILES_BONUS	= ft_lstnew_bonus \
		ft_lstadd_front_bonus \
		ft_lstsize_bonus \
		ft_lstlast_bonus \
		ft_lstadd_back_bonus \
		ft_lstdelone_bonus \
		ft_lstclear_bonus \
		ft_lstiter_bonus \
		ft_lstmap_bonus

OBJ_FILES_BONUS	= $(addsuffix .o, $(SRC_FILES_BONUS))

###################################################
## RULES

all: ${NAME}

${NAME}: ${OBJ_FILES}
	ar rcs ${NAME} ${OBJ_FILES}

bonus: $(NAME) $(OBJ_FILES_BONUS) $(BONUS_FLAG)

$(BONUS_FLAG): $(OBJ_FILES_BONUS)
	ar rcs $(NAME) $(OBJ_FILES_BONUS)
	@touch $(BONUS_FLAG)

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJ_FILES} ${OBJ_FILES_BONUS} $(BONUS_FLAG)
	@echo "\n"
	@echo "${BOLD}${ORANGE}		Deleted *.o MANDATORY and BONUS	files	${RESET}"
	@echo "\n"

fclean: clean
	rm -f ${NAME}
	@echo "\n"
	@echo "${BOLD}${ORANGE}		Deleted ${NAME}		${RESET}"
	@echo "\n"

re: fclean all

.PHONY: all clean fclean re bonus
