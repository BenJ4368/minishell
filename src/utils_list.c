/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 18:14:51 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/31 15:07:03 by bgaertne         ###   ########.fr       */
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
	new_node->content = content;
	if (*list == NULL)
		*list = new_node;
	else
	{
		last_node = get_last_node_cmd(*list);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}
