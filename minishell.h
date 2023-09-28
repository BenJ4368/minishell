/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:29:00 by bgaertne          #+#    #+#             */
/*   Updated: 2023/09/28 19:37:25 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "TheLibft/base/libft.h"
# include "TheLibft/ft_printf/ft_printf.h"
# include "TheLibft/get_next_line/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

# define CYAN "\001\x1b[36m\002"
# define MAGENTA "\001\x1b[35m\002"
# define BOLD "\001\x1b[1m\002"
# define STOP "\001\x1b[0m\002"

typedef struct ms_lst_s
{
	char			*cmd;
	struct ms_lst_s	*next;
	struct ms_lst_s	*prev;
}				t_ms_list;

typedef struct data_s
{
	char		**ms_env;
	char		*ms_path;
	char		*prompt;
	char		*input;
	char		**cmds;
}				t_data;

// main.c
void		copy_env(t_data *data, char **env);
void		get_path(t_data *data);
int			main(int argc, char **argv, char **env);

// history.c
int			init_ms_history(void);
int			ms_history(char *input);

// check_input.c
int			check_input(char *input);
int			check_unclosed_quotes(char *input, int i);
int			in_quotes(char *str, int x, int i, int quotes);
int			check_forbidden_char(char *input,char *excludes);

// prompt.c
void		prompt_builder(char **prompt, char *usr, char *cwd, int length);
void		prompt(t_data *data);

// utils_error.c
void		ms_error(char *msg);

// utils_free.c
void		free_minishell(t_data *data);

// utils_signal.c
void		sigint_handler(int signal);
void		sigquit_handler(int signal);

// utils_list.c
void		ms_list_add_back(t_ms_list **list, char *cmd);
t_ms_list	*get_last_node(t_ms_list *list);


#endif