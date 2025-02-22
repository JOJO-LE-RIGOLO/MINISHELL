# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jojo <jojo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 16:48:36 by jtudela           #+#    #+#              #
#    Updated: 2025/02/22 23:06:21 by jojo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### ARGUMENTS

NAME		= minishell
NAME_BONUS	= minishell_bonus
CFLAGS		= -Wall -Wextra -Werror -g
CC			= cc

# Libft
LIBFT_NAME			:= libmaster.a
LIBFT_PATH			:= Utils/
UTILS				:= $(LIBFT_PATH)$(LIBFT_NAME)

# Includes
INC_MANDATORY		= -I ./mandatory/inc
INC_BONUS			= -I ./bonus/inc

###################################################
## COLORS

RESET				:= \033[0m
BOLD				:= \033[1m
RED					:= \033[91m
GREEN				:= \033[92m
YELLOW				:= \033[33m
ORANGE				:= \033[93m
BLUE				:= \033[94m

###################################################
### SOURCES

## MANDATORY PART

# SRC
SRC_FILES	= main \
			main_utils \
			signals/ft_signal \
			ft_readline/ft_readline \
			ft_readline/ft_terminal \
			ft_readline/ft_printhistory \
			ft_readline/ft_history \
			builtins/builtins \
			builtins/pwd \
			builtins/cd \
			builtins/echo \
			builtins/env \
			builtins/export \
			parsing/tokeniser/tokeniser \
			parsing/tokeniser/tokeniser_utils1 \
			parsing/tokeniser/tokeniser_utils2 \
			parsing/tree/tree \
			parsing/tree/tree_utils

SRC_DIR := mandatory
SRC_MANDATORY := $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))

# OBJ
OBJ_FILES	:= $(SRC_MANDATORY:$(SRC_DIR)/%.c=$(SRC_DIR)/%.o)


## BONUS PART

# SRC
SRC_FILES_B	= main \
			pipex_bonus2 \
			ft_error_here_doc_bonus \
			here_doc_bonus \
			ft_error_bonus \
			ft_list_bonus \
			ft_start_bonus \
			ft_ultimate_parse_bonus \
			pipex_bonus1 \
			ft_close_bonus

SRC_DIR_B := bonus
SRC_BONUS := $(addprefix $(SRC_DIR_B)/, $(addsuffix .c, $(SRC_FILES_B)))

# OBJ
OBJ_FILES_B	:= $(SRC_BONUS:$(SRC_DIR_B)/%.c=$(SRC_DIR_B)/%.o)

###################################################
## RULES

all: $(UTILS) $(NAME)

bonus: $(UTILS) $(NAME_BONUS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) $(INC_MANDATORY) -c $< -o $@

$(SRC_DIR_B)/%.o: $(SRC_DIR_B)/%.c
	@$(CC) $(CFLAGS) $(INC_BONUS) -c $< -o $@

$(UTILS):
	@make -sC $(LIBFT_PATH)
	@echo "\n\n-----------------------------------------------\n\n"

$(NAME): $(OBJ_FILES) $(UTILS)
	@echo "$(BOLD)$(RED)🛠️      Compiling minishell    🛠️$(RESET)"
	@$(CC) $(CFLAGS) $(OBJ_FILES) $(UTILS) $(INC_MANDATORY) -lreadline -o $(NAME)
	@echo "$(BOLD)$(GREEN)🚀      Minishell fully compiled, ready to use       🚀$(RESET)"
	@echo "$(BOLD) Usage Mandatory : $(RESET)"
	@echo ""
	@echo "$(BOLD) $(YELLOW) ✨ Mandatory ✨ $(RESET) ./minishell $(RESET)"

$(NAME_BONUS): $(OBJ_FILES_B) $(UTILS)
	@echo "$(BOLD)$(RED)🛠️      Compiling minishell_bonus $(YELLOW)✨ BONUS ✨    🛠️$(RESET)"
	@echo "\n"
	@$(CC) $(CFLAGS) $(OBJ_FILES_B) $(UTILS) $(INC_BONUS) -o $(NAME_BONUS)
	@echo "$(BOLD)🚀      $(GREEN)Minishell_bonus $(YELLOW)✨ BONUS ✨ $(GREEN)fully compiled, ready to use       🚀$(RESET)"
	@echo ""
	@echo "$(BOLD) Usage Bonus : $(RESET)"
	@echo ""
	@echo "$(BOLD) $(YELLOW) ✨ BONUS 1 ✨ $(RESET) ./minishell_bonus $(RESET)"

clean:
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(OBJ_FILES)
	@rm -f $(OBJ_FILES_B)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned .o minishell's files   🌀$(RESET)"

fclean: clean
	@make fclean -sC $(LIBFT_PATH)
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "$(BOLD)$(ORANGE)🌀     Cleaned minishell exec       🌀$(RESET)"

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re rebonus