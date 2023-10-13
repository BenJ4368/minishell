/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:05:25 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/13 11:56:27 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_var_exists(t_ms_list **ms_envv, char *var)
{
	t_ms_list	*current;
	t_ms_list	*temp;
	int			i;

	current = *ms_envv;
	temp = NULL;
	i = 0;
	while (var[i] != '=')
		i++;
	while (current)
	{
		if (!strncmp(current->content, var, i))
		{
			temp = current;
			if (current->prev)
				current->prev->next = current->next;
			if (current->next)
				current->next->prev = current->prev;
			if (current == *ms_envv)
				*ms_envv = current->next;
			free(temp);
		}
		current = current->next;
	}
}

void	builtin_export(t_ms_list **ms_envv, char *var)
{
	if (check_export(var))
	{
		check_var_exists(ms_envv, var);
		ms_list_add_back(ms_envv, var);
	}
}
