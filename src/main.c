/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 10:41:29 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/27 15:22:38 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ms_unsupported_char(char *input)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		if (input[i] == '$' && input[i + 1] == '$')
			return (ms_error("Unsupported character mix: '$$'."), 1);
		if (input[i] == '&' && input[i + 1] == '&')
			return (ms_error("Unsupported character mix: '&&'."), 1);
		if (input[i] == '<' && input[i + 1] == '<' && input[i + 2] == '<')
			return (ms_error("Unsupported character mix: '<<<'."), 1);
		if (input[i] == '>' && input[i + 1] == '>' && input[i + 2] == '>')
			return (ms_error("Unsupported character mix: '>>>'."), 1);
		if (input[i] == '<' && input[i + 1] == '<' && input[i + 2] == '<')
			return (ms_error("Unsupported character mix: '<<<'."), 1);
		if (input[i] == '>' && input[i + 1] == '|')
			return (ms_error("Unsupported character mix: '>|'."), 1);
		if (input[i] == '<' && input[i + 1] == '|')
			return (ms_error("Unsupported character mix: '<|'."), 1);
	}
	return (0);
}

void	copy_env(t_ms_list **ms_envv, char **env)
{
	int		i;

	i = -1;
	while (env[++i])
		ms_list_add_back(ms_envv, env[i]);
}

int	main(int argc, char **argv, char **env)
{
	t_data	data;

	(void)argc;
	(void)argv;
	data.ms_envv = NULL;
	copy_env(&data.ms_envv, env);
	init_ms_history();
	rl_catch_signals = 0;
	while (1)
	{
		prompt(&data);
		signal(SIGINT, sigint_handler);
		signal(SIGQUIT, sigquit_handler);
		data.input = readline(data.prompt);
		free(data.prompt);
		if (data.input && !ft_strncmp(data.input, "exit", 4))
			exit (0);
		if (data.input && ft_strlen(data.input) >= 1)
		{
			ms_history(data.input);
			if (!check_input(data.input))
			{
				expand_input(&data);
				sanitize_input(&data);
				//builtin_cd(data.input);
				//builtin_echo(data.input, 1);
				//builtin_pwd();
				//builtin_export(&data.ms_envv, data.input);
				//builtin_env(data.ms_envv);
			}	
		}
	}
	free_minishell(&data);
	system("leaks minishell");
	return (0);
}
