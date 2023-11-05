/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_on_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:46:05 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/05 18:33:06 by bgaertne         ###   ########.fr       */
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
		remove_quoting(tab_space);
		j = -1;
		while (tab_space[++j])
			printf("   %s\n", tab_space[j]);
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

void	remove_quoting(char **tab)
{
	int		i;
	int		j;
	char	*temp;

	i = -1;
	while (tab[++i])
	{
		j = -1;
		temp = strdup(tab[i]);
		while (tab[i][++j])
		{
			if ((tab[i][j] == '"' && check_in_quotes(temp, j, 0, 0) == 0)
			 	|| (tab[i][j] == '\'' && check_in_quotes(temp, j, 0, 0) == 0))
				tab[i][j] = '\b';
		}
		free(temp);
		j = -1;
		while (tab[i][++j])
			if (tab[i][j] == '\b')
				ft_memmove(&tab[i][j], &tab[i][j + 1], ft_strlen(tab[i]) - j);
	}
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
