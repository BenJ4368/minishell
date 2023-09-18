/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:08:13 by bgaertne          #+#    #+#             */
/*   Updated: 2023/09/18 15:00:42 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_unclosed_quotes(char *str)
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
			if (str[i] == '"')
				i++;
			else
				ms_error("Unclosed double quotes.");
		}
		if (str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			if (str[i] == '\'')
				i++;
			else
				ms_error("Unclosed single quotes.");
		}
		else
			i++;
	}
}

void	lexer(t_data *data)
{
	int				i;
	int				j;
	char			**splited_cmd;
	enum e_state	state;
	enum e_token	type;

	i = 0;
	j = 0;
	state = GENERAL;
	type = 1;
	while (data->raw_cmd[i] == ' ' || data->raw_cmd[i] == '	')
		i++;
	check_unclosed_quotes(data->raw_cmd);
	splited_cmd = ms_split_into_tokens(data->raw_cmd);
	while (splited_cmd[j])
	{
		ms_list_add_back(&data->lexic, splited_cmd[j], type, state);
		free(splited_cmd[j]);
		j++;
	}
	free(splited_cmd);
}
