/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_on_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:46:05 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/02 15:28:21 by bgaertne         ###   ########.fr       */
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
	int			i;
	t_ms_cmd	*current;
	t_ms_cmd	*next;

	current = data->ms_cmd;
	while (current)
	{
		next = current->next;
		i = -1;
		while (current->content[++i])
			free(current->content[i]);
		free(current->content);
		free(current);
		current = next;
		data->ms_cmd = NULL;
	}
}
