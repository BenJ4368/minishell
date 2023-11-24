/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:49:29 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/24 12:22:37 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	empty_redirs_ouput(char *input)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		if (input[i] == '>')
		{
			i++;
			if (input[i] == '>')
				i++;
			if (input[i] == ' ')
			{
				while (input[i] == ' ')
					i++;
				if (input[i] && ft_isalnum(input[i]))
					return (0);
				return (1);
			}
			else
				return (1);
		}
	}
	return (0);
}

int	empty_redirs_input(char *input)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		if (input[i] == '<')
		{
			i++;
			if (input[i] == '<')
				i++;
			if (input[i] == ' ')
			{
				while (input[i] == ' ')
					i++;
				if (input[i] && ft_isalnum(input[i]))
					return (0);
				return (1);
			}
			else
				return (1);
		}
	}
	return (0);
}
