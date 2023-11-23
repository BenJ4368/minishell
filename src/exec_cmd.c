/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:53:42 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/23 15:31:21 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	filter_cmd(t_ms_cmd *cmd, t_data *data)
{
	char	*cmd_path;

	if (is_builtin(cmd->content[0]))
	{
		exec_builtin(cmd->content[0], cmd->content, data);
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

void	exec_builtin(char *cmd_name, char **cmd_line, t_data *data)
{
	int	len;

	len = ft_strlen(cmd_name);
	if (!ft_strncmp(cmd_name, "env\0", len + 1))
		builtin_env(data->ms_envv, data->exports);
	if (!ft_strncmp(cmd_name, "pwd\0", len + 1))
		builtin_pwd();
	if (!ft_strncmp(cmd_name, "cd\0", len + 1))
		builtin_cd(cmd_line[1], data->ms_fd);
	if (!ft_strncmp(cmd_name, "echo\0", len + 1))
		builtin_echo(cmd_line + 1);
	if (!ft_strncmp(cmd_name, "export\0", len + 1))
		builtin_export(&data->exports, (cmd_line + 1), data->ms_fd);
	if (!ft_strncmp(cmd_name, "unset\0", len + 1))
		builtin_unset(&data->exports, cmd_line + 1);
}

void	exec_cmd(t_ms_cmd *cmd, t_data *data, int *prevpipe_fd)
{
	pid_t	pid;
	int		*pipe_fd;

	if (cmd->next)
	{
		pipe_fd = malloc(sizeof(int) * 2);
		if (pipe(pipe_fd) == -1)
		{
			ms_error("Could not create pipe.", data->ms_fd),
			exit(EXIT_FAILURE);
		}
	}
	pid = fork();
	if (pid == -1)
	{
		ms_error("Could not create child process.", data->ms_fd);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (prevpipe_fd[0] != STDOUT_FILENO)
			dup2(prevpipe_fd[0], STDIN_FILENO);
		if (cmd->redir_in_fd != 0)
		{
			dup2(cmd->redir_in_fd, STDIN_FILENO);
			close(cmd->redir_in_fd);
		}
		if (cmd->next)
		{
			dup2(pipe_fd[1], STDOUT_FILENO);
			close(pipe_fd[0]);
		}
		if (cmd->redir_out_fd != 0)
		{
			dup2(cmd->redir_out_fd, STDOUT_FILENO);
			close(cmd->redir_out_fd);
		}
		close(prevpipe_fd[1]);
		filter_cmd(cmd, data);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (prevpipe_fd[0] != STDOUT_FILENO)
		{
			close(prevpipe_fd[0]);
			close(prevpipe_fd[1]);
		}
		if (cmd->next != NULL)
			exec_cmd(cmd->next, data, pipe_fd);
		waitpid(pid, &data->exit_status, 0);
	}
	if (cmd->next != NULL)
		free(pipe_fd);
}
