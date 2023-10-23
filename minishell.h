/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:29:00 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/23 10:45:44 by bgaertne         ###   ########.fr       */
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
# include <dirent.h>
# include <string.h>

# define CYAN "\001\x1b[36m\002"
# define MAGENTA "\001\x1b[35m\002"
# define BOLD "\001\x1b[1m\002"
# define STOP "\001\x1b[0m\002"

typedef struct ms_lst_s
{
	char			*content;
	struct ms_lst_s	*next;
	struct ms_lst_s	*prev;
}				t_ms_list;

typedef struct ms_cmd_s
{
	char			*line;
	struct ms_cmd_s	*next;
	struct ms_cmd_s	*prev;
}				t_ms_cmd;

typedef struct ms_data_s
{
	char			*ms_path;
	t_ms_list		*ms_envv;
	char			*prompt;
	char			*input;
	char			**cmds;
}				t_data;

// main.c
int			ms_unsupported_char(char *input);
void		copy_env(t_ms_list **ms_envv, char **env);
int			main(int argc, char **argv, char **env);

// expand_input.c
char		*get_var_value(t_ms_list *ms_envv, char *var_name);
char		*get_var_name(char *input);
void		expand_input(t_data *data);
int			has_var_sign(char *s);

// builtins_1.c
void		builtin_env(t_ms_list *ms_envv);
void		builtin_pwd(void);
void		builtin_cd(char *path);
void		builtin_echo(char *str, int n_option);

// builtin_2.c
void		check_var_exists(t_ms_list **ms_envv, char *var);
void		builtin_export(t_ms_list **ms_envv, char *var);

// history.c
int			init_ms_history(void);
int			ms_history(char *input);

// check_input.c
int			check_input(char *input);
int			check_unclosed_quotes(char *input, int i);
int			check_in_quotes(char *str, int x, int i, int quotes);
int			check_forbidden_char(char *input, char *excludes);
int			check_export(char *input);

// prompt.c
void		prompt_builder(char **prompt, char *usr, char *cwd, int length);
void		prompt(t_data *data);

// utils_error.c
void		ms_error(char *msg);
void		free_minishell(t_data *data);

// utils_signal.c
void		sigint_handler(int signal);
void		sigquit_handler(int signal);

// utils_list.c
void		ms_list_add_back(t_ms_list **list, char *cmd);
t_ms_list	*get_last_node(t_ms_list *list);

#endif