/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:09:07 by ssalor            #+#    #+#             */
/*   Updated: 2023/11/24 13:36:28 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	*exec_cmd1(t_data *data)
{
	int	*pipe_fd;

	pipe_fd = malloc(sizeof(int) * 2);
	if (pipe(pipe_fd) == -1)
	{
		ms_error("Could not create pipe.", data->ms_fd),
		exit(EXIT_FAILURE);
	}
	return (pipe_fd);
}

void	exec_cmd2(t_ms_cmd *cmd, t_data *data, int *prevpipe_fd, int *pipe_fd)
{
	if (prevpipe_fd[0] != STDOUT_FILENO)
		dup2(prevpipe_fd[0], STDIN_FILENO);
	if (cmd->redir_in_fd != 0)
	{
		dup2(cmd->redir_in_fd, STDIN_FILENO);
		close(cmd->redir_in_fd);
	}
	if (cmd->heredoc_key)
		do_heredoc(cmd, data);
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

void	exec_cmd3(int *prevpipe_fd)
{
	if (prevpipe_fd[0] != STDOUT_FILENO)
	{
		close(prevpipe_fd[0]);
		close(prevpipe_fd[1]);
	}
}

void	exec_cmd(t_ms_cmd *cmd, t_data *data, int *prevpipe_fd)
{
	pid_t	pid;
	int		*pipe_fd;

	if (cmd->next)
		pipe_fd = exec_cmd1(data);
	pid = fork();
	if (pid == -1)
	{
		ms_error("Could not create child process.", data->ms_fd);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
		exec_cmd2(cmd, data, prevpipe_fd, pipe_fd);
	else
	{
		exec_cmd3(prevpipe_fd);
		if (cmd->next != NULL)
			exec_cmd(cmd->next, data, pipe_fd);
		waitpid(pid, &data->exit_status, 0);
	}
	if (cmd->next != NULL)
		free(pipe_fd);
}
