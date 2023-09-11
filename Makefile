# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/24 10:41:40 by bgaertne          #+#    #+#              #
#    Updated: 2023/08/28 15:46:50 by bgaertne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell

_RED		=	\033[01;31m
_GREEN		=	\033[01;32m
_CYAN		=	\033[01;36m
_YELLOW		=	\033[01;33m
_PURPLE		=	\033[01;35m
_BOLD		=	\033[1m
_END		=	\033[00m

LIBFT		= TheLibft/libft.a
SRCS		= $(shell find ./src -iname "*.c")
OBJS		= ${SRCS:.c=.o}

all: $(LIBFT) $(NAME)
	@echo ""
	@echo "$(_CYAN)$(_BOLD)[Makefile]$(_END) $(_BOLD) $(_PURPLE)Project $(NAME) $(_GREEN)ready$(_END)"
	@echo ""

$(LIBFT):
	@cd TheLibft && $(MAKE)

%.o: %.c
	@gcc -Wall -Werror -Wextra -c $< -o $@ -lreadline 

$(NAME): $(OBJS)
	@gcc -Wall -Werror -Wextra -fsanitize=leak $(OBJS) $(LIBFT) -o $(NAME) -lreadline 
	@echo "$(_CYAN)$(_BOLD)[Makefile]$(_END) $(_BOLD)$(NAME) $(_GREEN)created$(_END)"

clean:
	@rm -f $(OBJS)
	@cd TheLibft && $(MAKE) clean
	@echo "$(_CYAN)$(_BOLD)[Makefile]$(_END) $(_BOLD)$(NAME) is now $(_YELLOW)clean$(_END)"

fclean: clean
	@rm -f $(NAME)
	@rm -f TheLibft/libft.a
	@echo "$(_CYAN)$(_BOLD)[Makefile]$(_END) $(_BOLD)libft.a $(_RED)deleted$(_END)"
	@echo "$(_CYAN)$(_BOLD)[Makefile]$(_END) $(_BOLD)$(NAME) $(_RED)deleted$(_END)"

re: clean all

.PHONY: all, clean, fclean, re