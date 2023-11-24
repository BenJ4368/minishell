/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:29:00 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/24 15:18:56 by ssalor           ###   ########.fr       */
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

typedef struct ms_norm_s
{
	char	*var_name;
	char	*var_value;
	char	*new_input;
}			t_ms_norm;

typedef struct ms_lst_s
{
	char			*content;
	struct ms_lst_s	*next;
	struct ms_lst_s	*prev;
}				t_ms_list;

typedef struct ms_cmd_s
{
	char			**content;
	char			*redir_type;
	int				redir_out_fd;
	int				redir_in_fd;
	char			*heredoc_key;
	int				*quoted;
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
	int				ms_fd;
	int				exit_status;
}				t_data;

// main.c
void		ms_prepare(t_data *data, char **env);
void		do_minishell(t_data *data);
int			main(int argc, char **argv, char **env);
// exec_cmd_main.c
void		exec_cmd(t_ms_cmd *cmd, t_data *data, int *prevpipe_fd);
int			*exec_cmd1(t_data *data);
void		exec_cmd2(t_ms_cmd *cmd, t_data *data,
				int *prevpipe_fd, int *pipe_fd);
void		exec_cmd3(int *prevpipe_fd);
// exec_cmd.c
void		filter_cmd(t_ms_cmd *cmd, t_data *data);
char		*find_cmd(char *cmd_name, t_data *data);
void		exec_builtin(t_ms_cmd *cmd, t_data *data);
void		exec_builin2(t_ms_cmd *cmd);
void		do_heredoc(t_ms_cmd *cmd, t_data *data);
// unsupp_char.c
int			ms_unsupported_char(char *input, int ms_fd);
int			ms_unsupported_char2(char *input, int i, int ms_fd);
int			ms_unsupported_char3(char *input, int i, int ms_fd);
// ft_split_unquoted.c
char		**ft_split_unquoted(char const *s, char c);
int			ft_split_unquoted_count_words(char const *s, char c);
int			ft_split_unquoted_write(char **tab, char const *s, char c);
void		ft_split_unquoted_write_word(char *dest, const char *src, char c);
int			ft_split_unquoted_nope(char **tab, int size);
// split_on_pipe.c
int			split_on_pipe(t_data *data);
int			*remove_quoting(char **tab);
void		extract_redirs(t_ms_cmd *node);
int			tablen(char **tab);
void		check_redir_type(t_ms_cmd *node, int *i);
// expand_input_main.c
int			expand_input1(int j, char *new_input, char *var_value);
char		*expand_input2(t_data *data, char *var_value, char *var_name);
void		expand_input3(t_data *data, char *new_input, char *var_name);
void		expand_input(t_data *data, int i, int j);
// expand_input.c
char		*get_var_value(t_ms_list *ms_envv,
				t_ms_list *exports, char *var_name);
char		*get_var_name(char *input);
int			has_var_sign(char *s);
// sanitize_input.c
void		sanitize_input(t_data *data);
int			is_white_space(char c);
int			check_for_blank_cmd(char **tab);
// builtins_1.c
void		builtin_env(t_ms_list *ms_envv, t_ms_list *exports);
void		builtin_pwd(void);
void		builtin_cd(char *path, int ms_fd);
void		builtin_echo(char **args);
// builtin_2.c
void		builtin_export(t_ms_list **ms_envv, char **vars, int ms_fd);
void		builtin_unset(t_ms_list **ms_envv, char **vars);
int			is_builtin(char *cmd_name);
void		check_then_delete_var(t_ms_list **ms_envv, char *var);
// history.c
int			init_ms_history(int ms_fd);
int			ms_history(char *input, int ms_fd);
// check_input.c
int			check_input(char *input, int ms_fd);
int			check_unclosed_quotes(char *input, int i, int ms_fd);
int			check_in_quotes(const char *str, int x, int i, int quotes);
int			check_forbidden_char(char *input, char *excludes);
int			check_export(char *input, int ms_fd);
// prompt.c
void		prompt_builder(char **prompt, char *usr, char *cwd, int length);
void		prompt(t_data *data);
// utils_signal.c
void		sigint_handler(int signal);
void		sigquit_handler(int signal);
int			check_interactive(char *input);
void		free_tab(char **tab);
char		*globalisation(char *input, int elephant);
// utils_list.c
void		ms_list_add_back(t_ms_list **list, char *cmd);
t_ms_list	*get_last_node_list(t_ms_list *list);
void		ms_cmd_add_back(t_ms_cmd **list, char **content);
t_ms_cmd	*get_last_node_cmd(t_ms_cmd *list);
char		**list_to_tab(t_ms_list *envv);
// utils.c
void		ms_error(char *msg, int ms_fd);
void		copy_env(t_ms_list **ms_envv, char **env);
void		free_ms(t_data *data, t_ms_list	*current, t_ms_list	*next);
void		free_cmd(t_data *data);
int			only_white_spaces(char *str);
// set_redir.c
void		set_redir_output(t_ms_cmd *node, int i);
void		set_redir_output_append(t_ms_cmd *node, int i);
void		set_redir_input(t_ms_cmd *node, int i);
void		set_redir_heredoc(t_ms_cmd *node, int i);
// check_redirs.c
int			empty_redirs_ouput(char *input);
int			empty_redirs_input(char *input);

#endif