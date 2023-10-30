/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:37:11 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/30 12:56:34 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ms_error(char *msg)
{
	printf("Minishell: Error:	%s\n", msg);
}

void	free_minishell(t_data *data)
{
	int	i;
	
	if (data->ms_path)
		free(data->ms_path);
	if (data->input)
		free(data->input);
	if (data->prompt)
		free(data->prompt);
	while (data->ms_envv)
	{
		free(data->ms_envv);
		data->ms_envv = data->ms_envv->next;
	}
	while (data->ms_cmd)
	{
		i = -1;
		while (data->ms_cmd->content[++i])
			free(data->ms_cmd->content[i]);
		free(data->ms_cmd);
		data->ms_cmd = data->ms_cmd->next;
	}
}
