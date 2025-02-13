# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jotudela <jotudela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 16:48:36 by jtudela           #+#    #+#              #
#    Updated: 2024/11/18 14:38:47 by jotudela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### ARGUMENTS

NAME		= libftprintf.a
CFLAGS		= -Wall -Wextra -Werror
CC		= cc

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

SRC_FILES	= ft_printf \
			ft_print_format_c \
			ft_print_format_i \
			ft_print_format_p \
			ft_print_format_s \
			ft_print_format_u \
			ft_print_format_xX 

OBJ_FILES	= $(addsuffix .o, $(SRC_FILES))

###################################################
## RULES

all: ${NAME}

${NAME}: ${OBJ_FILES}
	ar rcs ${NAME} ${OBJ_FILES}

%.o: %.c
	${CC} ${CFLAGS} -c $< -o $@

clean:
	rm -f ${OBJ_FILES}
	@echo "\n"
	@echo "${BOLD}${ORANGE}		Deleted *.o MANDATORY files	${RESET}"
	@echo "\n"

fclean: clean
	rm -f ${NAME}
	@echo "\n"
	@echo "${BOLD}${ORANGE}		Deleted ${NAME}		${RESET}"
	@echo "\n"

re: fclean all

.PHONY: all clean fclean re
