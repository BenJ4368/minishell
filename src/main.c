/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:41:29 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/13 17:46:01 by bgaertne         ###   ########.fr       */
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
	int dummy[2];

	expand_input(data);
	sanitize_input(data);
	split_on_pipe(data);
	/*t_ms_cmd	*runner;
	runner = data->ms_cmd;
	int c = 0;
	while (runner)
	{
		c++;
		int i = -1;
		while (runner->content[++i])
			printf("cmd n=%i, content[%i] = %s\n", c, i, runner->content[i]);
		printf("\n");
		runner = runner->next;
	}
	printf("execution:\n");*/
	dummy[0] = STDOUT_FILENO;
	dummy[1] = STDIN_FILENO;
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
	while (1)
	{
		prompt(&data);
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, sigquit_handler);
		data.input = readline(data.prompt);
		free(data.prompt);
		if (data.input && !ft_strncmp(data.input, "exit\0", 5))
			return (free_ms(&data, NULL, NULL), exit(0), 0);
		if (data.input && ft_strlen(data.input) >= 1)
		{
			ms_history(data.input, data.ms_fd);
			if (!check_input(data.input, data.ms_fd))
				do_minishell(&data);
		}
	}
}
