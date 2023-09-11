/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:30:23 by bgaertne          #+#    #+#             */
/*   Updated: 2023/09/10 22:51:25 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ms_list	*get_last_node(t_ms_list *lexic)
{
	while (lexic->next)
		lexic = lexic->next;
	return (lexic);
}

void	ms_list_add_back(t_ms_list **lexic, char *content,
			enum e_token type, enum e_state state)
{
	t_ms_list	*new_node;
	t_ms_list	*last_node;

	new_node = ft_calloc(sizeof(t_ms_list), 1);
	new_node->content = content;
	new_node->length = (int)ft_strlen(content);
	new_node->type = type;
	new_node->state = state;
	if (*lexic == NULL)
		*lexic = new_node;
	else
	{
		last_node = get_last_node(*lexic);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}
