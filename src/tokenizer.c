/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 12:32:25 by bgaertne          #+#    #+#             */
/*   Updated: 2023/09/18 13:18:38 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ms_split_write_token(char *dest, char *src, int length)
{
	int	i;

	i = 0;
	while (length != 0)
	{
		dest[i] = src[i];
		i++;
		length--;
	}
	dest[i] = '\0';
}

void	ms_split_get_tokens(char **tab, char *cmd)
{
	int	i;
	int	j;
	int	word;

	word = 0;
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == ' ' || cmd[i] == '\0')
			i++;
		else
		{
			j = 0;
			if (cmd[i] == '"')
			{
				j++;
				while (cmd[i + j] != '"')
					j++;
				j++;
			}
			else if (cmd[i] == '\'')
			{
				j++;
				while (cmd[i + j] != '\'')
					j++;
				j++;
			}
			else
				while (cmd[i + j] != ' ' && cmd[i + j] != '\0')
					j++;
			tab[word] = (char *)malloc(sizeof(char) * (j + 1));
			ms_split_write_token(tab[word], cmd + i, j);
			i += j;
			word++;
		}
	}
	tab[word] = 0;
}

int	ms_split_count_tokens(char *cmd)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (cmd[i])
	{
		if (cmd[i] == '"')
		{
			i++;
			while (cmd[i] != '"')
				i++;
		}
		if (cmd[i] == '\'')
		{
			i++;
			while (cmd[i] != '\'')
				i++;
		}
		if ((cmd[i + 1] == ' ' || cmd[i + 1] == '\0') == 1
			&& (cmd[i] == ' ' || cmd[i] == '\0') == 0)
			count++;
		i++;
	}
	return (count);
}

char	**ms_split_into_tokens(char *cmd)
{
	char	**tab;

	if (!cmd)
		return (NULL);
	tab = malloc(sizeof(char *) * (ms_split_count_tokens(cmd) + 1));
	if (!tab)
		return (NULL);
	tab[ms_split_count_tokens(cmd)] = 0;
	ms_split_get_tokens(tab, cmd);
	return (tab);
}
