/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:41:29 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/24 15:07:06 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ms_prepare(t_data *data, char **env)
{
	int		i;
	char	*temp;

	data->ms_envv = NULL;
	data->exports = NULL;
	data->ms_cmd = NULL;
	data->ms_paths = NULL;
	data->input = NULL;
	data->prompt = NULL;
	data->ms_fd = STDERR_FILENO;
	data->exit_status = 0;
	copy_env(&data->ms_envv, env);
	data->tab_envv = list_to_tab(data->ms_envv);
	data->ms_paths = ft_split_unquoted(getenv("PATH"), ':');
	i = -1;
	while (data->ms_paths[++i])
	{
		temp = ft_strdup(data->ms_paths[i]);
		free(data->ms_paths[i]);
		data->ms_paths[i] = ft_strjoin(temp, "/");
		free(temp);
		temp = NULL;
	}
	init_ms_history(data->ms_fd);
	rl_catch_signals = 0;
}

void	do_minishell(t_data *data)
{
	int			dummy[2];

	expand_input(data, -1, 0);
	sanitize_input(data);
	if (split_on_pipe(data) == -1)
		return ;
	dummy[0] = dup(STDOUT_FILENO);
	dummy[1] = dup(STDIN_FILENO);
	if (is_builtin(data->ms_cmd->content[0]) && data->ms_cmd->next == NULL)
		exec_builtin(data->ms_cmd, data);
	else
		exec_cmd(data->ms_cmd, data, dummy);
	free_cmd(data);
	free(data->input);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	(void)argc;
	(void)argv;
	ms_prepare(&data, env);
	signal(SIGINT, sigint_handler);
	signal(SIGQUIT, sigquit_handler);
	while (1)
	{
		prompt(&data);
		data.input = readline(data.prompt);
		if (data.input == NULL)
			exit(0);
		free(data.prompt);
		if (data.input && !ft_strncmp(data.input, "exit\0", 5))
			return (free_ms(&data, NULL, NULL), exit(0), 0);
		globalisation(data.input, 1);
		if (data.input && ft_strlen(data.input) >= 1)
		{
			ms_history(data.input, data.ms_fd);
			if (!check_input(data.input, data.ms_fd))
				do_minishell(&data);
		}
	}
}
