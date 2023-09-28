/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:55:27 by bgaertne          #+#    #+#             */
/*   Updated: 2023/09/28 09:32:50 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int check_input(char *input)
{
	if (check_unclosed_quotes(input, 0))
		return (1);
	if (check_forbidden_char(input, "\\;&*"))
		return (ms_error("Forbidden character use."), 1);
	return (0);
}

int check_unclosed_quotes(char *input, int i)
{
	while (input[i])
	{
		if (input[i] == '"')
		{
			i++;
			while (input[i] && input[i] != '"')
				i++;
			if (!input[i])
				return (ms_error("Unclosed double quotes."), 1);
			i++;
		}
		else if (input[i] == '\'')
		{
			i++;
			while (input[i] && input[i] != '\'')
				i++;
			if (!input[i])
				return (ms_error("Unclosed single quotes."), 1);
			i++;
		}
		else
			i++;
	}
	return (0);
}

int in_quotes(char *str, int x, int i, int quotes)
{
	while (str[i])
	{
		if (str[i] == '\'')
			quotes = 1;
		while (str[i] && quotes == 1)
		{
			if (str[++i] == '\'')
				quotes = 0;
			if (i == x)
				return (quotes);
		}
		if (str[i] == '"')
			quotes = 2;
		while (str[i] && quotes == 2)
		{
			if (str[++i] == '"')
				quotes = 0;
			if (i == x)
				return (quotes);
		}
		if (i++ == x)
			return (quotes);
	}
	return (0);
}

int	check_forbidden_char(char *input,char *excludes)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		j = 0;
		while (excludes[j])
		{
			if (input[i] == excludes[j] && !in_quotes(input, i, 0, 0))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}