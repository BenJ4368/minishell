/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:55:27 by bgaertne          #+#    #+#             */
/*   Updated: 2023/09/26 12:42:54 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_input(char *input)
{
	int	i;

	i = 0;
	if (check_unclosed_quotes(input, 0))
		return (1);
	while (input[i])
	{
		if (in_quotes(input, i))
			printf("1");
		else
			printf("0");
		i++;
	}
	printf("\n");
	return (0);
}

int	check_unclosed_quotes(char *input, int i)
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

int	in_quotes(char *str, int x)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] && str[i] != '"')
				i++;
			if (i > x)
				return (1);
		}
		else if (str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			if (i > x)
				return (1);
		}
		else
		{
			i++;
			if (i > x)
				return (0);
		}			
	}
	return (0);
}
