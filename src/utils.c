/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:37:11 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/05 19:45:13 by bgaertne         ###   ########.fr       */
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
	char	*shlvl;

	i = -1;
	while (env[++i])
	{
		if (!ft_strncmp(env[i], "SHLVL=", 6))
		{
			shlvl = ft_itoa(ft_atoi(&env[i][6]) + 1);
			ms_list_add_back(ms_envv, ft_strjoin("SHLVL=", shlvl));
			free(shlvl);
			printf("%i\n", ft_atoi(&env[i][6]) + 1);
		}
		else
			ms_list_add_back(ms_envv, env[i]);
	}
}

void	free_ms(t_data *data)
{
	t_ms_list	*current;
	t_ms_list	*next;
	int			i;

	current = data->exports;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
		data->exports = NULL;
	}
	i = -1;
	while (data->tab_envv[++i])
		free(data->tab_envv[i]);
	free(data->tab_envv);
	while (data->ms_envv)
	{
		if (!ft_strncmp(data->ms_envv->content, "SHLVL=", 6))
			free(data->ms_envv->content);
		data->ms_envv = data->ms_envv->next;
	}
}

void	free_cmd(t_data *data)
{
	int			i;
	t_ms_cmd	*current;
	t_ms_cmd	*next;

	current = data->ms_cmd;
	while (current)
	{
		next = current->next;
		i = -1;
		while (current->content[++i])
			free(current->content[i]);
		free(current->content);
		free(current);
		current = next;
		data->ms_cmd = NULL;
	}
}
