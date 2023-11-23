/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:36:07 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/23 14:00:53 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_redir_output(t_ms_cmd *node, int i)
{
	char	**tab;
	int		j;
	int		y;

	node->redir_fd = open(node->content[i + 1], O_RDWR | O_CREAT, 77777);
	tab = malloc(sizeof(char *) * (tablen(node->content) - 2));
	j = -1;
	y = -1;
	while (node->content[++j])
	{
		if (j != i && j != (i + 1))
		{
			node->quoted[++y] = node->quoted[j];
			tab[y] = ft_strdup(node->content[j]);
		}
	}
	tab[++y] = 0;
	free_tab(node->content);
	node->content = tab;
	printf("redir_ouput\n");
}

void	set_redir_output_append(t_ms_cmd *node, int i)
{
	char	**tab;
	int		j;
	int		y;

	node->redir_fd = open(node->content[i + 1], O_RDWR | O_CREAT | O_APPEND, 77777);
	tab = malloc(sizeof(char *) * (tablen(node->content) - 2));
	j = -1;
	y = -1;
	while (node->content[++j])
	{
		if (j != i && j != (i + 1))
		{
			node->quoted[++y] = node->quoted[j];
			tab[y] = ft_strdup(node->content[j]);
		}
	}
	tab[++y] = 0;
	free_tab(node->content);
	node->content = tab;
	printf("redir_ouput_append\n");
}

void	set_redir_input(t_ms_cmd *node, int i)
{
	(void)node;
	(void)i;
	printf("redir_input\n");
}

void	set_redir_heredoc(t_ms_cmd *node, int i)
{
	(void)node;
	(void)i;
	printf("redir_heredoc\n");
}
