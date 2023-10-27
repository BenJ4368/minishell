/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:15:33 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/27 12:56:02 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	prompt_builder(char **prompt, char *usr, char *cwd, int length)
{
	ft_strlcat(*prompt, CYAN BOLD, length);
	ft_strlcat(*prompt, "[", length);
	ft_strlcat(*prompt, usr, length);
	ft_strlcat(*prompt, "] ", length);
	ft_strlcat(*prompt, MAGENTA, length);
	ft_strlcat(*prompt, cwd, length);
	ft_strlcat(*prompt, " % ", length);
	ft_strlcat(*prompt, STOP, length);
}

void	prompt(t_data *data)
{
	int		i;
	int		length;
	char	*usr;
	char	*cwd;

	usr = getenv("USER");
	cwd = getcwd(NULL, 0);
	i = 0;
	while (cwd[i + 1])
		i++;
	while (cwd[i - 1] != '/')
		i--;
	length = ft_strlen(usr) + ft_strlen(cwd + i)
		+ ft_strlen(MAGENTA) + ft_strlen(BOLD)
		+ ft_strlen(CYAN) + ft_strlen(STOP) + 7;
	data->prompt = ft_calloc(sizeof(char), length);
	prompt_builder(&(data->prompt), usr, cwd + i, length);
	free(cwd);
}
