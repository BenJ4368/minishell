/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:55:27 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/24 12:36:26 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_input(char *input, int ms_fd)
{
	if (input[1] == '|')
		return (ms_error("Syntax error near unexpected token '|'", ms_fd), 1);
	if (check_unclosed_quotes(input, 0, ms_fd))
		return (1);
	if (check_forbidden_char(input, "\\;&*"))
		return (ms_error("Forbidden character use.", ms_fd), 1);
	if (ms_unsupported_char(input, ms_fd))
		return (1);
	if (empty_redirs_ouput(input) || empty_redirs_input(input))
		return (ms_error("Syntax error near unexpected token 'newline'", ms_fd),
			1);
	if (only_white_spaces(input))
		return (1);
	return (0);
}

int	check_unclosed_quotes(char *input, int i, int ms_fd)
{
	while (input[i])
	{
		if (input[i] == '"')
		{
			i++;
			while (input[i] && input[i] != '"')
				i++;
			if (!input[i])
				return (ms_error("Unclosed double quotes.", ms_fd), 1);
			i++;
		}
		else if (input[i] == '\'')
		{
			i++;
			while (input[i] && input[i] != '\'')
				i++;
			if (!input[i])
				return (ms_error("Unclosed single quotes.", ms_fd), 1);
			i++;
		}
		else
			i++;
	}
	return (0);
}

int	check_in_quotes(const char *str, int x, int i, int quotes)
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

int	check_forbidden_char(char *input, char *excludes)
{
	int	i;
	int	j;

	i = 0;
	while (input[i])
	{
		j = 0;
		while (excludes[j])
		{
			if (input[i] == excludes[j] && !check_in_quotes(input, i, 0, 0))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_export(char *input, int ms_fd)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[0] == '=')
			return (ms_error("export: '=': not a valid identifier", ms_fd), 0);
		if (input[i] == '=')
			return (1);
		i++;
	}
	return (0);
}
