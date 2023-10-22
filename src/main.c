/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:41:29 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/22 12:46:20 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	copy_env(t_ms_list **ms_envv, char **env)
{
	int		i;
	char	buff[100];

	i = -1;
	while (env[++i])
		ms_list_add_back(ms_envv, env[i]);
	ft_bzero(buff, 100);
	ft_strlcat(buff, "$=", 3);
	ft_strlcat(buff, ft_itoa(getpid()), ft_strlen(ft_itoa(getpid())) + 4);
	ms_list_add_back(ms_envv, ft_strdup(buff));
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
		if (data.input && !ft_strncmp(data.input, "exit", 4))
			break ;
		if (data.input && ft_strlen(data.input) >= 1)
		{
			if (!check_input(data.input))
			{
				ms_history(data.input);
				expand_input(&data);
				printf("%s\n", data.input);
			}	
		}
	}
	free_minishell(&data);
	system("leaks minishell");
	return (0);
}
