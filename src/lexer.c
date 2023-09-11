/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:08:13 by bgaertne          #+#    #+#             */
/*   Updated: 2023/09/11 12:51:53 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	while (data->raw_cmd[i])
	{
		if (data->raw_cmd[i] == (WHITE_SPACE || NEW_LINE || QUOTE || DQUOTE
				|| ESCAPE || VAR || PIPE || REDIR_IN || REDIR_OUT))
			ft_printf("deal\n");
		i++;
	}
	splited_cmd = ft_split(data->raw_cmd, ' ');
	while (splited_cmd[j])
	{
		ms_list_add_back(&data->lexic, splited_cmd[j], type, state);
		free(splited_cmd[j]);
		j++;
	}
	free(splited_cmd);
}
