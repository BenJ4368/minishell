/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 18:05:25 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/02 17:12:33 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_then_delete_var(t_ms_list **ms_exports, char *var)
{
	t_ms_list	*current;
	t_ms_list	*temp;
	int			i;

	current = *ms_exports;
	temp = NULL;
	i = 1;
	while (var[i] && var[i] != '=')
		i++;
	while (current)
	{
		if (!strncmp(current->content, var, i + 1))
		{
			temp = current;
			if (current->prev)
				current->prev->next = current->next;
			if (current->next)
				current->next->prev = current->prev;
			if (current == *ms_exports)
				*ms_exports = current->next;
			free(temp->content);
			free(temp);
		}
		current = current->next;
	}
}

void	builtin_export(t_ms_list **ms_exports, char **vars)
{
	int	i;

	i = -1;
	while (vars[++i])
	{
		if (check_export(vars[i]))
		{
			check_then_delete_var(ms_exports, vars[i]);
			ms_list_add_back(ms_exports, ft_strdup(vars[i]));
		}
	}
}

void	builtin_unset(t_ms_list **ms_exports, char **vars)
{
	int		i;
	char	*var;

	i = -1;
	while (vars[++i])
	{
		var = ft_strjoin(vars[i], "=");
		check_then_delete_var(ms_exports, var);
		free(var);
		var = NULL;
	}
}

int	is_builtin(char *cmd_name)
{
	int	len;

	len = ft_strlen(cmd_name);
	if (!ft_strncmp(cmd_name, "env\0", len + 1)
		|| !ft_strncmp(cmd_name, "pwd\0", len + 1)
		|| !ft_strncmp(cmd_name, "cd\0", len + 1)
		|| !ft_strncmp(cmd_name, "echo\0", len + 1)
		|| !ft_strncmp(cmd_name, "export\0", len + 1)
		|| !ft_strncmp(cmd_name, "unset\0", len + 1))
		return (1);
	return (0);
}
