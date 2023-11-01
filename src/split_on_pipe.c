/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_on_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:46:05 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/01 13:55:54 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	split_on_pipe(t_data *data)
{
	int		i;
	int		j;
	char	**tab_pipe;
	char	**tab_space;

	i = -1;
	tab_pipe = ft_split_unquoted(data->input, '|');
	while (tab_pipe[++i])
	{
		tab_space = ft_split_unquoted(tab_pipe[i], ' ');
		ms_cmd_add_back(&data->ms_cmd, ft_tabdup((const char **)tab_space));
		j = -1;
		while (tab_space[++j])
			free(tab_space[j]);
		free(tab_space);
		tab_space = NULL;
		free(tab_pipe[i]);
	}
	free(tab_pipe);
	tab_pipe = NULL;
}

void	free_cmd(t_data *data)
{
	int	i;

	while (data->ms_cmd)
	{
		i = -1;
		while (data->ms_cmd->content[++i])
			free(data->ms_cmd->content[i]);
		free(data->ms_cmd->content);
		data->ms_cmd = data->ms_cmd->next;
	}
}
