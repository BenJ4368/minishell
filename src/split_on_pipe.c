/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_on_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:46:05 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/23 14:39:50 by ssalor           ###   ########.fr       */
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

void	extract_redirs(t_ms_cmd *node)
{
	int	i;

	i = -1;
	node->redir_out_fd = 0;
	node->redir_in_fd = 0;
	while (node->content[++i])
	{
		if (node->content[i] && !ft_strncmp(node->content[i], ">\0", 2))
		{
			set_redir_output(node, i);
			i = 0;
		}
		if (node->content[i] && !ft_strncmp(node->content[i], ">>\0", 3))
		{
			set_redir_output_append(node, i);
			i = 0;
		}
		if (node->content[i] && !ft_strncmp(node->content[i], "<\0", 2))
		{
			set_redir_input(node, i);
			i = 0;
		}
		/*if (node->content[i] && !ft_strncmp(node->content[i], "<<\0", 3))
		{
			set_redir_heredoc(node, i);
			i = 0;
		}*/
	}
}

int	tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
