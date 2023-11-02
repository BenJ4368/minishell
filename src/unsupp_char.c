/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsupp_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:39:00 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/02 15:28:26 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ms_unsupported_char(char *input)
{
	int	i;

	i = -1;
	while (input[++i])
	{
		if ((input[0] == '|' || ((input[i] == '|'
						&& check_in_quotes(input, i, 0, 0) == 0)
					&& (input[i + 1] == '|'
						&& check_in_quotes(input, i + 1, 0, 0) == 0))))
			return (ms_error("Syntax error near unexpected token '|'"), 1);
		if ((input[i] == '$' && check_in_quotes(input, i, 0, 0) != 1)
			&& (input[i + 1] == '$'
				&& check_in_quotes(input, i, 0, 0) != 1))
			return (ms_error("Unsupported character mix: '$$'."), 1);
		if ((input[i] == '&' && check_in_quotes(input, i, 0, 0) == 0)
			&& (input[i + 1] == '&'
				&& check_in_quotes(input, i + 1, 0, 0) == 0))
			return (ms_error("Unsupported character mix: '&&'."), 1);
		if (ms_unsupported_char2(input, i))
			return (1);
		if (ms_unsupported_char3(input, i))
			return (1);
	}
	return (0);
}


int	ms_unsupported_char2(char *input, int i)
{
	if ((input[i] == '>' && check_in_quotes(input, i, 0, 0) == 0)
		&& (input[i + 1] == '>' && check_in_quotes(input, i + 1, 0, 0) == 0)
		&& (input[i + 2] == '>'
			&& check_in_quotes(input, i + 2, 0, 0) == 0))
		return (ms_error("Unsupported character mix: '>>>'."), 1);
	if ((input[i] == '<' && check_in_quotes(input, i, 0, 0) == 0)
		&& (input[i + 1] == '<'
			&& check_in_quotes(input, i + 1, 0, 0) == 0)
		&& (input[i + 2] == '<'
			&& check_in_quotes(input, i + 2, 0, 0) == 0))
		return (ms_error("Unsupported character mix: '<<<'."), 1);
	if ((input[i] == '>' && check_in_quotes(input, i, 0, 0) == 0)
		&& (input[i + 1] == '|'
			&& check_in_quotes(input, i + 1, 0, 0) == 0))
		return (ms_error("Unsupported character mix: '>|'."), 1);
	if ((input[i] == '<' && check_in_quotes(input, i, 0, 0) == 0)
		&& (input[i + 1] == '|'
			&& check_in_quotes(input, i + 1, 0, 0) == 0))
		return (ms_error("Unsupported character mix: '<|'."), 1);
	return (0);
}

int	ms_unsupported_char3(char *input, int i)
{
	if ((input[i] == '<' && check_in_quotes(input, i, 0, 0) == 0)
		&& (input[i + 1] == '<'
			&& check_in_quotes(input, i + 1, 0, 0) == 0)
		&& (input[i + 2] == '<'
			&& check_in_quotes(input, i + 2, 0, 0) == 0))
		return (ms_error("Unsupported character mix: '<<<'."), 1);
	return (0);
}
