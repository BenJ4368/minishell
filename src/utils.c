/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:37:11 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/02 17:13:32 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ms_error(char *msg)
{
	printf("Minishell: Error:	%s\n", msg);
}

void	copy_env(t_ms_list **ms_envv, char **env)
{
	int		i;

	i = -1;
	while (env[++i])
		ms_list_add_back(ms_envv, env[i]);
}

void	free_exports(t_data *data)
{
	t_ms_list	*current;
	t_ms_list	*next;

	current = data->exports;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
		data->exports = NULL;
	}
}
