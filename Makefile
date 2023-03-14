# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mac <mac@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/26 01:57:19 by bahbibe           #+#    #+#              #
#    Updated: 2023/03/14 22:41:51 by mac              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

Off		=\033[0m
Black	=\033[0;30m
Red		=\033[0;31m
Green	=\033[0;32m
Yellow	=\033[0;33m
Blue	=\033[0;34m
Purple	=\033[0;35m
Cyan	=\033[0;36m
White	=\033[0;37m

NAME = minishell
PARSE_PATH = ./src/parser/
EXECUTION_PATH = ./src/execution/
OBG = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra
# CFLAGS += -fsanitize=address -g3
SRCS = main.c \
		$(PARSE_PATH)get_next_line/get_next_line.c \
		$(PARSE_PATH)get_next_line/get_next_line_utils.c \
		$(PARSE_PATH)utils/ft_calloc.c \
		$(PARSE_PATH)utils/ft_split.c \
		$(PARSE_PATH)utils/split_utils.c \
		$(PARSE_PATH)utils/ft_strdup.c \
		$(PARSE_PATH)utils/ft_substr.c \
		$(PARSE_PATH)utils/ft_strcmp.c \
		$(PARSE_PATH)linked_list_utils/add_back_lst.c \
		$(PARSE_PATH)linked_list_utils/add_front_lst.c \
		$(PARSE_PATH)linked_list_utils/create_node.c \
		$(PARSE_PATH)linked_list_utils/lst_clear.c\
		$(PARSE_PATH)lexer_utils/init_lexer_node.c \
		$(PARSE_PATH)lexer_utils/lexer_utils.c \
		$(PARSE_PATH)utils/ft_atoi.c \
		$(PARSE_PATH)utils/ft_putstr.c \
		$(PARSE_PATH)utils/ft_itoa.c \
		$(PARSE_PATH)utils/custom_split.c \
		$(PARSE_PATH)utils/utils.c \
		$(PARSE_PATH)parser_utils/parser_utils.c \
		$(PARSE_PATH)parser_utils/parser.c \
		$(PARSE_PATH)utils/create_mini_env.c \
		$(PARSE_PATH)linked_list_utils/env_del_node.c \
		$(PARSE_PATH)parser_utils/expand_quotes.c \
		$(PARSE_PATH)parser_utils/expand_quotes_utils.c \
		$(PARSE_PATH)parser_utils/syntax_check.c \
		$(PARSE_PATH)builtins/builtins_utils.c \
		$(PARSE_PATH)builtins/cd.c  \
		$(PARSE_PATH)errors_free/parse_error.c \
		$(PARSE_PATH)builtins/echo.c  \
		$(PARSE_PATH)builtins/env.c  \
		$(PARSE_PATH)builtins/exit.c  \
		$(PARSE_PATH)builtins/export.c  \
		$(PARSE_PATH)builtins/pwd.c  \
		$(PARSE_PATH)builtins/unset.c \
		$(EXECUTION_PATH)executor.c \
		$(EXECUTION_PATH)fd.c \
		$(EXECUTION_PATH)status.c \
		$(EXECUTION_PATH)utils.c \

all: $(NAME)

$(NAME): $(OBG)
	@stty -echoctl
	@$(CC) $(CFLAGS) -lreadline $(OBG) -L ~/homebrew/Cellar/readline/8.2.1/lib -o $(NAME)
	@echo "$(Green)Minishell Compiled ✅$(Off)"

clean:
	rm -rf $(OBG)
fclean: clean
	rm -rf $(NAME)
re: fclean all
.PHONY: all clean fclean re
.SILENT: $(OBJS)
# readline is keg-only, which means it was not symlinked into /usr/local,
# because macOS provides BSD libedit.

# For compilers to find readline you may need to set:
#   export LDFLAGS="-L/usr/local/opt/readline/lib"
#   export CPPFLAGS="-I/usr/local/opt/readline/include"

# ==> Summary
# 🍺  /usr/local/Cellar/readline/8.2.1: 50 files, 1.7MB
# ==> Running `brew cleanup readline`...
# Disable this behaviour by setting HOMEBREW_NO_INSTALL_CLEANUP.
# Hide these hints with HOMEBREW_NO_ENV_HINTS (see `man brew`).





