/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:41:29 by bgaertne          #+#    #+#             */
/*   Updated: 2023/09/28 19:35:49 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * Creates a copy of the environment variables into the data structure.
 * 
 * @param data Pointer to the data structure.
 * @param env Main()-received environment variables.
 */
void	copy_env(t_data *data, char **env)
{
	int	i;

	i = 0;
	while (env[i])
		i++;
	data->ms_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (env[++i])
		data->ms_env[i] = ft_strdup(env[i]);
	data->ms_env[i] = 0;
}
void	get_path(t_data *data)
{
	int	i;

	i = 0;
	while (data->ms_env[i])
	{
		if (!ft_strncmp(data->ms_env[i], "PATH=", 5))
		{
			data->ms_path = ft_strdup(data->ms_env[i]);
			break;
		}
		i++;
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data		data;


	(void)argc;
	(void)argv;
	copy_env(&data, env);
	get_path(&data);
	close(init_ms_history());
	rl_catch_signals = 0;
	while (1)
	{
		prompt(&data);
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, sigquit_handler);
		data.input = readline(data.prompt);
		free(data.prompt);
		if (data.input)
		{
			if (!ft_strncmp(data.input, "exit", 4))
				break ;
			if (!check_input(data.input))
			{
				ms_history(data.input);
				data.cmds = ft_split(data.input, '|');
				printf("Input: %s\n", data.input);
				int i = 0;
				while (data.cmds[i])
				{
					printf("Cmds: %s\n", data.cmds[i]);
					i++;
				}
			}
		}
	}
	free_minishell(&data);
	system("leaks minishell");
	return (0);
}
