/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:55:27 by bgaertne          #+#    #+#             */
/*   Updated: 2023/09/25 15:31:01 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_input(char *input)
{
	if (check_unclosed_quotes(input, 0))
		return (1);
	if (ft_strchr(input, ))
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
				return (ms_error("Unclosed double quotes."), 1);s
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
