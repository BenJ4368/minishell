/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:41:29 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/02 17:02:58 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ms_prepare(t_data *data, char **env)
{
	data->ms_envv = NULL;
	data->exports = NULL;
	data->ms_cmd = NULL;
	data->ms_paths = NULL;
	data->input = NULL;
	data->prompt = NULL;
	copy_env(&data->ms_envv, env);
	data->ms_paths = ft_split_unquoted(getenv("PATH"), ':');
	init_ms_history();
	rl_catch_signals = 0;
}

void	do_minishell(t_data *data)
{
	expand_input(data);
	sanitize_input(data);
	split_on_pipe(data);
	liftoff(data);
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
			return (free_exports(&data), exit(0), 0);
		if (data.input && ft_strlen(data.input) >= 1)
		{
			ms_history(data.input);
			if (!check_input(data.input))
				do_minishell(&data);
		}
	}
}


/* TO DO LIST

enlever les quotes* avant de les utiliser dans les fonctions
(*uniquement les quotes qui sont pas dans des quotes hein)

*/