/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_on_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:46:05 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/30 17:02:43 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	split_on_pipe(t_data *data)
{
	int		i;
	char	**tab_pipe;
	char	**tab_space;

	i = -1;
	tab_pipe = ft_split_unquoted(data->input, '|');
	while (tab_pipe[++i])
	{
		tab_space = ft_split_unquoted(tab_pipe[i], ' ');
		ms_cmd_add_back(&data->ms_cmd, tab_space);
	}

	//prints
	t_ms_cmd	*runner;
	int			j;
	runner = data->ms_cmd;
	i = 0;
	while (runner)
	{
		i++;
		j = -1;
		while (runner->content[++j])
			printf("#%i  #%i %s\n", i, j, runner->content[j]);
		runner = runner->next;
	}
}
