/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:53:42 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/24 13:43:48 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	filter_cmd(t_ms_cmd *cmd, t_data *data)
{
	char	*cmd_path;

	if (is_builtin(cmd->content[0]))
	{
		exec_builtin(cmd, data);
		exit(EXIT_SUCCESS);
	}
	if (ft_strncmp(cmd->content[0], "./", 2) == 0
		|| ft_strncmp(cmd->content[0], "/", 1) == 0)
		execve(cmd->content[0], cmd->content, data->tab_envv);
	cmd_path = find_cmd(cmd->content[0], data);
	if (!cmd_path)
	{
		ms_error("Command not found.", data->ms_fd);
		exit(EXIT_FAILURE);
	}
	else
	{
		execve(cmd_path, cmd->content, data->tab_envv);
		free(cmd_path);
	}
}

char	*find_cmd(char *cmd_name, t_data *data)
{
	int		i;
	char	*cmd_path;

	i = -1;
	while (data->ms_paths[++i])
	{
		cmd_path = ft_strjoin(data->ms_paths[i], cmd_name);
		if (access(cmd_path, F_OK) == 0 && access(cmd_path, X_OK) == 0)
			return (cmd_path);
		free(cmd_path);
		cmd_path = NULL;
	}
	return (NULL);
}

void	exec_builin2(t_ms_cmd *cmd)
{
	if (cmd->redir_in_fd != 0)
	{
		dup2(cmd->redir_in_fd, STDIN_FILENO);
		close(cmd->redir_in_fd);
	}
	if (cmd->redir_out_fd != 0)
	{
		dup2(cmd->redir_out_fd, STDOUT_FILENO);
		close(cmd->redir_out_fd);
	}
}

void	exec_builtin(t_ms_cmd *cmd, t_data *data)
{
	int	len;
	int	saved_stdin;
	int	saved_stdout;

	saved_stdin = dup(STDIN_FILENO);
	saved_stdout = dup(STDOUT_FILENO);
	len = ft_strlen(cmd->content[0]);
	if (!ft_strncmp(cmd->content[0], "env\0", len + 1))
		builtin_env(data->ms_envv, data->exports);
	if (!ft_strncmp(cmd->content[0], "pwd\0", len + 1))
		builtin_pwd();
	if (!ft_strncmp(cmd->content[0], "cd\0", len + 1))
		builtin_cd(cmd->content[1], data->ms_fd);
	if (!ft_strncmp(cmd->content[0], "echo\0", len + 1))
		builtin_echo(cmd->content + 1);
	if (!ft_strncmp(cmd->content[0], "export\0", len + 1))
		builtin_export(&data->exports, (cmd->content + 1), data->ms_fd);
	if (!ft_strncmp(cmd->content[0], "unset\0", len + 1))
		builtin_unset(&data->exports, cmd->content + 1);
	dup2(saved_stdin, STDIN_FILENO);
	dup2(saved_stdout, STDOUT_FILENO);
	close(saved_stdin);
	close(saved_stdout);
}

void	do_heredoc(t_ms_cmd *cmd, t_data *data)
{
	char	*input;

	dup2(1, STDIN_FILENO);
	input = NULL;
	while (1)
	{
		input = get_next_line(STDIN_FILENO);
		write(data->ms_fd, input, ft_strlen(input));
		write(data->ms_fd, "\n", 1);
		if (input == cmd->heredoc_key)
			break ;
	}
}
