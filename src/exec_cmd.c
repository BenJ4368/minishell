/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:53:42 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/13 17:50:43 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	filter_cmd(t_ms_cmd *cmd, t_data *data)
{
	char	*cmd_path;

	// char buffer[1024];
	// int bytes_read;
	// while ((bytes_read = read(STDIN_FILENO, buffer, sizeof(buffer))) > 0)
	// {
	// 	write(data->ms_fd, buffer, bytes_read);
	// 	write(data->ms_fd, "\n", 1);
	// 	if (buffer[0] == 'q')
	// 		break ;
	// }
	int i = -1;
	while (cmd->content[++i])
	{
		write(data->ms_fd, cmd->content[i], ft_strlen(cmd->content[i]));
		write(data->ms_fd, "\n", 1);
	}
	write(data->ms_fd, "\n", 1);
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
		// write(data->ms_fd, "A\n", 2);
		ms_error("Command not found.", data->ms_fd);
		exit(EXIT_FAILURE);
	}
	else
	{
		// write(data->ms_fd, "B\n", 2);
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

	if (cmd->next != NULL)
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
		// write(data->ms_fd, "### CHILD ### ", 15);
		// write(data->ms_fd, "\n", 1);
		// write(data->ms_fd, "prev[0] ", 8);
		// write(data->ms_fd, ft_itoa(prevpipe_fd[0]), 2);
		// write(data->ms_fd, "\n", 1);
		// write(data->ms_fd, "prev[1] ", 8);
		// write(data->ms_fd, ft_itoa(prevpipe_fd[1]), 2);
		// write(data->ms_fd, "\n", 1);
		// write(data->ms_fd, "pipe[0] ", 8);
		// write(data->ms_fd, ft_itoa(pipe_fd[0]), 2);
		// write(data->ms_fd, "\n", 1);
		// write(data->ms_fd, "pipe[1] ", 8);
		// write(data->ms_fd, ft_itoa(pipe_fd[1]), 2);
		// write(data->ms_fd, "\n", 1);

		if (prevpipe_fd[0] != STDOUT_FILENO)
		{
			// write(data->ms_fd, "prev[0] != stdin", 17);
			// write(data->ms_fd, "\n", 1);
			dup2(prevpipe_fd[0], STDIN_FILENO);
		}
		if (cmd->next != NULL)
		{
			// write(data->ms_fd, "cmd->next != NULL", 18);
			// write(data->ms_fd, "\n", 1);
			dup2(pipe_fd[1], STDOUT_FILENO);
		}
		close(pipe_fd[0]);
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
