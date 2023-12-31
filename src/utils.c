/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 13:37:11 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/23 15:33:25 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	only_white_spaces(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!is_white_space(str[i]))
			return (0);
	}
	return (1);
}

void	ms_error(char *msg, int ms_fd)
{
	int	i;

	write(ms_fd, "Minishell: Error:	", 18);
	i = -1;
	while (msg[++i])
		write(ms_fd, &msg[i], 1);
	write(ms_fd, "\n", 1);
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
		}
		else
			ms_list_add_back(ms_envv, ft_strdup(env[i]));
	}
}

void	free_ms(t_data *data, t_ms_list	*current, t_ms_list	*next)
{
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
	current = data->ms_envv;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
		data->ms_envv = NULL;
	}
	i = -1;
	while (data->tab_envv[++i])
		free(data->tab_envv[i]);
	free(data->tab_envv);
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
		free(current->quoted);
		free(current->content);
		free(current);
		current = next;
		data->ms_cmd = NULL;
	}
}
