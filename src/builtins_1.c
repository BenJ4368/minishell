/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:18:22 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/06 19:08:55 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_env(t_ms_list *ms_envv, t_ms_list *exports)
{
	t_ms_list	*runner;

	runner = ms_envv;
	while (runner)
	{
		printf("%s\n", runner->content);
		runner = runner->next;
	}
	runner = exports;
	while (runner)
	{
		printf("%s\n", runner->content);
		runner = runner->next;
	}
}

void	builtin_pwd(void)
{
	char	cwd_buff[100];

	getcwd(cwd_buff, 100);
	write(1, &cwd_buff, ft_strlen(cwd_buff));
	write(1, "\n", 1);
}

void	builtin_cd(char *path, int ms_fd)
{
	if (chdir(path) == -1)
		ms_error("not a directory.", ms_fd);
}

void	builtin_echo(char **args)
{
	int	i;
	int	j;
	int	n_option;

	n_option = 0;
	i = 0;
	if (args[0] && !ft_strncmp(args[0], "-n\0", 3))
	{
		i++;
		n_option = 1;
	}
	while (args[i])
	{
		j = -1;
		while (args[i][++j])
		{
			if (args[i][j] != '\n')
				write(1, &args[i][j], 1);
		}
		i++;
		if (args[i])
			write(1, " ", 1);
	}
	if (!n_option)
		write(1, "\n", 1);
}
