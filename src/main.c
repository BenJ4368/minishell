/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:41:29 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/06 18:33:26 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	copy_env(t_ms_list **ms_envv, char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		ms_list_add_back(ms_envv, env[i]);
}

int	main(int argc, char **argv, char **env)
{
	t_data		data;

	(void)argc;
	(void)argv;
	data.ms_envv = NULL;
	copy_env(&data.ms_envv, env);
	close(init_ms_history());
	rl_catch_signals = 0;
	while (1)
	{
		prompt(&data);
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, sigquit_handler);
		data.input = readline(data.prompt);
		free(data.prompt);
		if (ft_strlen(data.input) >= 1)
		{
			if (!check_input(data.input))
			{
				ms_history(data.input);
				builtin_export(&data.ms_envv, data.input);
				builtin_env(data.ms_envv);
			}
			if (!ft_strncmp(data.input, "exit", 4))
				break ;
		}
	}
	free_minishell(&data);
	system("leaks minishell");
	return (0);
}