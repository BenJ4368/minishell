/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_on_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:46:05 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/17 13:36:58 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	split_on_pipe(t_data *data)
{
	int		i;
	int		j;
	char	**tab_pipe;
	char	**tab_space;

	i = -1;
	tab_pipe = ft_split_unquoted(data->input, '|');
	if (check_for_blank_cmd(tab_pipe))
		return (ms_error("Syntax error near unexpected token '|'",
				data->ms_fd), -1);
	while (tab_pipe[++i])
	{
		tab_space = ft_split_unquoted(tab_pipe[i], ' ');
		extract_redirs_and_quoting(tab_space);
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
	return (0);
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
