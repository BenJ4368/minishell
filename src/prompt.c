/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:15:33 by bgaertne          #+#    #+#             */
/*   Updated: 2023/09/25 14:15:34 by bgaertne         ###   ########.fr       */
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

/**
 * Stores both 'CurrentWorkingDirectory' and 'Username' variables in buffers.
 * Then calls build_prompt() to create the string that'll be used by
 * read_line(). Stores any user-given input received in the data structure.
 * 
 * @param data Pointer to the data structure.
 */
void	prompt(t_data *data)
{
	int		i;
	int		length;
	char	cwd_buff[100];
	char	usr_buff[100];

	ft_strlcpy(usr_buff, getenv("USER"), ft_strlen(getenv("USER")) + 1);
	getcwd(cwd_buff, 100);
	i = 0;
	while (cwd_buff[i + 1])
		i++;
	while (cwd_buff[i - 1] != '/')
		i--;
	length = ft_strlen(usr_buff) + ft_strlen(cwd_buff + i)
		+ ft_strlen(MAGENTA BOLD CYAN STOP) + 7;
	data->prompt = malloc(sizeof(char) * length);
	prompt_builder(&(data->prompt), usr_buff, cwd_buff + i, length);
}
