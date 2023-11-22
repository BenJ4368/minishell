/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_signal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:39:35 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/22 19:34:53 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*globalisation(char *input, int flag)
{
	static char	*g_input;

	if (flag == 1)
	{
		if (g_input)
			free(g_input);
		g_input = ft_strdup(input);
	}
	return (g_input);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

int	check_interactive(char *input)
{
	char	**argv;
	int		i;

	if (!input || !input[0])
		return (0);
	argv = ft_split((const char *)input, ' ');
	i = -1;
	while (argv[++i])
	{
		if (((i == 0 || !ft_strncmp(argv[i], ">", 1)
					|| !ft_strncmp(argv[i], ">>", 2)
					|| !ft_strncmp(argv[i], "|", 1))
				&& (!ft_strncmp(argv[i], "cat", 3)
					|| !ft_strncmp(argv[i], "grep", 4)
					|| !ft_strncmp(argv[i], "bc", 2))))
		{
			globalisation(NULL, 1);
			return (free_tab(argv), 1);
		}
		globalisation(NULL, 1);
	}
	return (free_tab(argv), 0);
}

void	sigint_handler(int signal)
{
	if (signal != SIGINT)
		return ;
	if (!check_interactive(globalisation(NULL, 0)))
	{
	ft_printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	}
}

void	sigquit_handler(int signal)
{
	if (signal == SIGQUIT)
		return ;
}
