# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/04 11:05:41 by bgaertne          #+#    #+#              #
#    Updated: 2023/11/04 16:05:24 by bgaertne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

_RED		=	\033[01;31m
_GREEN		=	\033[01;32m
_CYAN		=	\033[01;36m
_YELLOW		=	\033[01;33m
_PURPLE		=	\033[01;35m
_BOLD		=	\033[1m
_END		=	\033[00m

BASE_DIR = base/
FTPRINTF_DIR = ft_printf/
GNL_DIR = get_next_line/

BASE_SRC =	ft_atoi ft_atol ft_bzero ft_calloc ft_isalnum ft_isalpha \
			ft_isascii ft_isdigit ft_isprint ft_itoa ft_memchr \
			ft_memcmp ft_memcpy ft_memmove ft_memset ft_putchar_fd \
			ft_putendl_fd ft_putnbr_fd ft_putstr_fd ft_split \
			ft_strchr ft_strdup ft_striteri ft_strjoin ft_strlcat \
			ft_strlcpy ft_strlen ft_strmapi ft_strncmp ft_strnstr \
			ft_strrchr ft_strtrim ft_substr ft_tolower ft_toupper \
			ft_tabdup \

FTPRINTF_SRC =	ft_printf \
				ft_analyze_format \
				ft_process_hex \
				ft_process_pointer \
				ft_process_unsint \
				ft_print_utils \

GNL_SRC =	get_next_line \

OBJ =	$(addprefix $(BASE_DIR), $(addsuffix .o, $(BASE_SRC))) \
		$(addprefix $(FTPRINTF_DIR), $(addsuffix .o, $(FTPRINTF_SRC))) \
		$(addprefix $(GNL_DIR), $(addsuffix .o, $(GNL_SRC)))

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@echo "$(_CYAN)$(_BOLD)[Makefile]$(_END) $(_BOLD)$(NAME) $(_GREEN)created$(_END)"

%.o: %.c
	@gcc -Wall -Werror -Wextra -o $@ -c $?

clean:
	@rm -rf $(OBJ)
	@echo "$(_CYAN)$(_BOLD)[Makefile]$(_END) $(_BOLD)Libft is now $(_YELLOW)clean$(_END)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(_CYAN)$(_BOLD)[Makefile]$(_END) $(_BOLD)$(NAME) $(_RED)deleted$(_END)"

re: fclean all

.PHONY : all clean fclean re