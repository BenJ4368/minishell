/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_on_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:46:05 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/21 14:13:44 by bgaertne         ###   ########.fr       */
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

int	*remove_quoting(char **tab)
{
	int		i;
	int		j;
	int		*quoting;
	char	*temp;

	quoting = ft_calloc(sizeof(int), tablen(tab));
	i = -1;
	while (tab[++i])
	{
		j = -1;
		temp = strdup(tab[i]);
		while (tab[i][++j])
		{
			quoting[i] = 0;
			if ((tab[i][j] == '"' && check_in_quotes(temp, j, 0, 0) == 0)
				|| (tab[i][j] == '\'' && check_in_quotes(temp, j, 0, 0) == 0))
			{
				tab[i][j] = 5;
				quoting[i] = 1;
			}
		}
		free(temp);
	}
	return (quoting);
}

int	*extract_redirs_and_quoting(t_ms_cmd *node)
{
	int	*quoting;
	int	i;

	i = -1;
	while (node->content[++i])
	{
		if (!ft_strncmp(node->content[i], ">\0", 2))
			set_redir_output(node, i);
		if (!ft_strncmp(node->content[i], ">>\0", 3))
			set_redir_output_append(node, i);
		if (!ft_strncmp(node->content[i], "<\0", 3))
			set_redir_input(node, i);
		if (!ft_strncmp(node->content[i], "<<\0", 3))
			set_redir_heredoc(node, i);
	}
	quoting = remove_quoting(node->content);
	return (quoting);
}

int	tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
