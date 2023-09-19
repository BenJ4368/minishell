/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:41:29 by bgaertne          #+#    #+#             */
/*   Updated: 2023/09/19 14:03:16 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	sigint_handler(int signal)
{
	if (signal == SIGINT)
	{
		ft_printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

int	main(int argc, char **argv, char **env)
{
	t_data		data;
	t_ms_list	*temp;

	(void)argc;
	(void)argv;
	copy_env(&data, env);
	rl_catch_signals = 0;
	data.lexic = NULL;
	while (1)
	{
		prompt(&data);
		signal(SIGINT, sigint_handler);
		data.raw_cmd = readline(data.prompt);
		free(data.prompt);
		if (!ft_strncmp(data.raw_cmd, "exit", 4))
			break ;
		if (data.raw_cmd)
		{
			lexer(&data);
			while (data.lexic)
			{
				printf("%s %i %i\n", data.lexic->content, data.lexic->type, data.lexic->state);
				temp = data.lexic;
				data.lexic = data.lexic->next;
				free(temp);
			}
			//break ;
		}
	}
	free_minishell(&data);
	system("leaks minishell");
	return (0);
}
