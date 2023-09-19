/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:08:13 by bgaertne          #+#    #+#             */
/*   Updated: 2023/09/19 17:34:47 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_unclosed_quotes(char *str)
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
				return (ms_error("Unclosed double quotes."), 1);
		}
		if (str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			if (str[i] == '\'')
				i++;
			else
				return (ms_error("Unclosed single quotes."), 1);
		}
		else
			i++;
	}
	return (0);
}

char	*process_token(char *raw_token)
{
	
}

enum e_type	get_token_type(char *raw_token)
{
	
}

enum e_state	get_token_state(char *raw_token)
{
	
}

void	lexer(t_data *data)
{
	int				i;
	int				j;
	char			**splited_cmd;
	enum e_state	state;
	enum e_type	type;

	i = 0;
	j = 0;
	state = GENERAL;
	type = 1;
	while (data->raw_cmd[i] == ' ' || data->raw_cmd[i] == '	')
		i++;
	if (check_unclosed_quotes(data->raw_cmd))
		return ;
	
	splited_cmd = ms_split_into_tokens(data->raw_cmd);
	while (splited_cmd[j])
	{
		ms_list_add_back(&data->lexic, process_token(splited_cmd[j]),
			get_token_type(splited_cmd[j]), get_token_state(splited_cmd[j]));
		free(splited_cmd[j]);
		j++;
	}
	free(splited_cmd);
}
