/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:29:00 by bgaertne          #+#    #+#             */
/*   Updated: 2023/09/18 13:18:40 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../TheLibft/base/libft.h"
# include "../TheLibft/ft_printf/ft_printf.h"
# include "../TheLibft/get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

# define CYAN "\001\x1b[36m\002"
# define MAGENTA "\001\x1b[35m\002"
# define BOLD "\001\x1b[1m\002"
# define STOP "\001\x1b[0m\002"

enum e_token
{
	WORD = -1,
	WHITE_SPACE = ' ',
	NEW_LINE = '\n',
	QUOTE = '\'',
	DQUOTE = '\"',
	ESCAPE = '\\',
	VAR = '$',
	PIPE = '|',
	REDIR_IN = '<',
	REDIR_OUT = '>',
	HERE_DOC,
	DREDIR_OUT,
};

enum e_state
{
	IN_QUOTE,
	IN_DQUOTE,
	GENERAL,
};

typedef struct ms_list_s
{
	char				*content;
	int					length;
	enum e_token		type;
	enum e_state		state;
	struct ms_list_s	*next;
	struct ms_list_s	*prev;
}					t_ms_list;

typedef struct data_s
{
	char		**ms_env;
	char		*prompt;
	char		*raw_cmd;
	t_ms_list	*lexic;
}				t_data;

// main.c
void		copy_env(t_data *data, char **env);
int			main(int argc, char **argv, char **env);

// prompt.c
void		prompt_builder(char **prompt, char *usr, char *cwd, int length);
void		prompt(t_data *data);

// free_utils.c
void		free_minishell(t_data *data);
void		ms_error(char *msg);

// lexer.c
void		lexer(t_data *data);
void		check_unclosed_quotes(char *str);

// tokenizer.c
void		ms_split_write_token(char *dest, char *src, int length);
void		ms_split_get_tokens(char **tab, char *cmd);
int			ms_split_count_tokens(char *cmd);
char		**ms_split_into_tokens(char *cmd);

// list_utils.c
void		ms_list_add_back(t_ms_list **lexic, char *content,
				enum e_token type, enum e_state state);

#endif