/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:36:07 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/22 19:54:09 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_redir_output(t_ms_cmd *node, int i)
{
	char	**tab;
	int		j;
	int		y;

	//node->redir_fd = open(node->content[i + 1], O_RDWR | O_CREAT, 77777);
	tab = malloc(sizeof(char *) * tablen(node->content) - 1);
	j = 0;
	y = 0;
	while (node->content[j])
	{
		if (j == i || j == i + 1)
			j++;
		else
		{
			node->quoted[y] = node->quoted[j];
			tab[y++] = ft_strdup(node->content[j++]);
		}
	}
	tab[y] = 0;
	free_tab(node->content);
	node->content = tab;
	printf("redir_ouput\n");
}

void	set_redir_output_append(t_ms_cmd *node, int i)
{
	(void)node;
	(void)i;
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
