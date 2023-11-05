/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:29:00 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/04 20:10:40 by bgaertne         ###   ########.fr       */
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
# include <sys/wait.h>

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
	char			**content;
	struct ms_cmd_s	*next;
	struct ms_cmd_s	*prev;
}				t_ms_cmd;

typedef struct ms_data_s
{
	char			**ms_paths;
	t_ms_list		*ms_envv;
	char			**tab_envv;
	t_ms_list		*exports;
	t_ms_cmd		*ms_cmd;
	char			*prompt;
	char			*input;
	int				exit_status;
}				t_data;

// main.c
void		ms_prepare(t_data *data, char **env);
void		do_minishell(t_data *data);
int			main(int argc, char **argv, char **env);
// filter_cmd.c
void		filter_cmd(t_ms_cmd *cmd, t_data *data);
char		*find_cmd(char *cmd_name, t_data *data);
void		exec_builtin(char *cmd_name, char **cmd_line, t_data *data);
void		exec_cmd(char *cmd_path, t_data *data);
// unsupp_char.c
int			ms_unsupported_char(char *input);
int			ms_unsupported_char2(char *input, int i);
int			ms_unsupported_char3(char *input, int i);
// ft_split_unquoted.c
char		**ft_split_unquoted(char const *s, char c);
int			ft_split_unquoted_count_words(char const *s, char c);
int			ft_split_unquoted_write(char **tab, char const *s, char c);
void		ft_split_unquoted_write_word(char *dest, const char *src, char c);
int			ft_split_unquoted_nope(char **tab, int size);
// split_on_pipe.c
void		split_on_pipe(t_data *data);
void		free_cmd(t_data *data);
// expand_input.c
char		*get_var_value(t_ms_list *ms_envv,
				t_ms_list *exports, char *var_name);
char		*get_var_name(char *input);
void		expand_input(t_data *data);
int			has_var_sign(char *s);
// sanitize_input.c
void		sanitize_input(t_data *data);
int			is_white_space(char c);
// builtins_1.c
void		builtin_env(t_ms_list *ms_envv, t_ms_list *exports);
void		builtin_pwd(void);
void		builtin_cd(char *path);
void		builtin_echo(char **args);
// builtin_2.c
void		builtin_export(t_ms_list **ms_envv, char **vars);
void		builtin_unset(t_ms_list **ms_envv, char **vars);
int			is_builtin(char *cmd_name);
void		check_then_delete_var(t_ms_list **ms_envv, char *var);
// history.c
int			init_ms_history(void);
int			ms_history(char *input);
// check_input.c
int			check_input(char *input);
int			check_unclosed_quotes(char *input, int i);
int			check_in_quotes(const char *str, int x, int i, int quotes);
int			check_forbidden_char(char *input, char *excludes);
int			check_export(char *input);
// prompt.c
void		prompt_builder(char **prompt, char *usr, char *cwd, int length);
void		prompt(t_data *data);
// utils_signal.c
void		sigint_handler(int signal);
void		sigquit_handler(int signal);
// utils_list.c
void		ms_list_add_back(t_ms_list **list, char *cmd);
t_ms_list	*get_last_node_list(t_ms_list *list);
void		ms_cmd_add_back(t_ms_cmd **list, char **content);
t_ms_cmd	*get_last_node_cmd(t_ms_cmd *list);
char		**list_to_tab(t_ms_list *envv);
// utils.c
void		ms_error(char *msg);
void		copy_env(t_ms_list **ms_envv, char **env);
void		free_ms(t_data *data);

#endif