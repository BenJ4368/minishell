/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:14:51 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/22 14:09:01 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_ms_list	*get_last_node_list(t_ms_list *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

void	ms_list_add_back(t_ms_list **list, char *content)
{
	t_ms_list	*new_node;
	t_ms_list	*last_node;

	new_node = ft_calloc(sizeof(t_ms_list), 1);
	new_node->content = content;
	if (*list == NULL)
		*list = new_node;
	else
	{
		last_node = get_last_node_list(*list);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

t_ms_cmd	*get_last_node_cmd(t_ms_cmd *list)
{
	while (list->next)
		list = list->next;
	return (list);
}

void	ms_cmd_add_back(t_ms_cmd **list, char **content)
{
	t_ms_cmd	*new_node;
	t_ms_cmd	*last_node;

	new_node = ft_calloc(sizeof(t_ms_cmd), 1);
	new_node->quoted = remove_quoting(content);
	new_node->content = content;
	if (*list == NULL)
		*list = new_node;
	else
	{
		last_node = get_last_node_cmd(*list);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
	extract_redirs(new_node);
}

char	**list_to_tab(t_ms_list *ms_envv)
{
	char		**tab_envv;
	t_ms_list	*runner;
	int			i;

	i = 0;
	runner = ms_envv;
	while (runner)
	{
		runner = runner->next;
		i++;
	}
	tab_envv =  ft_calloc(sizeof(char *), i + 1);
	runner = ms_envv;
	i = -1;
	while (runner)
	{
		tab_envv[++i] = ft_strdup(runner->content);
		runner = runner->next;
	}
	return (tab_envv);
}
