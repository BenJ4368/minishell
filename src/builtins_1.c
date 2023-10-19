/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:18:22 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/18 10:59:12 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	builtin_env(t_ms_list *ms_envv)
{
	t_ms_list	*runner;

	runner = ms_envv;
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

void	builtin_cd(char *path)
{
	if (chdir(path) == -1)
		ms_error("not a directory.");
}

void	builtin_echo(char *str, int n_option)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] != '\n')
			write(1, &str[i], 1);
	}
	if (n_option)
		write(1, "\n", 1);
}
