/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:53:42 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/06 13:00:55 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	filter_cmd(t_ms_cmd *cmd, t_data *data)
{
	char	*cmd_path;

	if (is_builtin(cmd->content[0]))
		return (exec_builtin(cmd->content[0],
				cmd->content, data));
	if (ft_strncmp(cmd->content[0], "./", 2) == 0
		|| ft_strncmp(cmd->content[0], "/", 1) == 0)
		return (exec_cmd(cmd->content[0], data));
	cmd_path = find_cmd(cmd->content[0], data);
	if (!cmd_path)
		return (ms_error("Command not found."));
	else
		return (exec_cmd(cmd_path, data), free(cmd_path));
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
		builtin_cd(cmd_line[1]);
	if (!ft_strncmp(cmd_name, "echo\0", len + 1))
		builtin_echo(cmd_line + 1);
	if (!ft_strncmp(cmd_name, "export\0", len + 1))
		builtin_export(&data->exports, (cmd_line + 1));
	if (!ft_strncmp(cmd_name, "unset\0", len + 1))
		builtin_unset(&data->exports, cmd_line + 1);
}

void	exec_cmd(char *cmd_path, t_data *data)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (ms_error("Could not create child process."));
	else if (pid == 0)
	{
		execve(cmd_path, data->ms_cmd->content, data->tab_envv);
		return (ms_error("Error while executing command."));
	}
	else
		waitpid(pid, &data->exit_status, 0);
}
