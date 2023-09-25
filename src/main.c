/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:41:29 by bgaertne          #+#    #+#             */
/*   Updated: 2023/09/25 15:10:30 by bgaertne         ###   ########.fr       */
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

int	main(int argc, char **argv, char **env)
{
	t_data		data;

	(void)argc;
	(void)argv;
	copy_env(&data, env);
	rl_catch_signals = 0;
	while (1)
	{
		prompt(&data);
		signal(SIGINT, sigint_handler);
		data.input = readline(data.prompt);
		free(data.prompt);
		if (data.input)
		{
			if (!ft_strncmp(data.input, "exit", 4))
				break ;
			if (!check_input(data.input))
				printf("%s\n", data.input);
		}
	}
	free_minishell(&data);
	system("leaks minishell");
	return (0);
}
