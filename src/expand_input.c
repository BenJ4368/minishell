/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:47:01 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/24 13:52:54 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*get_var_value(t_ms_list *ms_envv, t_ms_list *exports, char *var_name)
{
	t_ms_list	*runner;

	if (!var_name)
		return (NULL);
	runner = ms_envv;
	while (runner)
	{
		if (!ft_strncmp(runner->content, var_name, ft_strlen(var_name))
			&& runner->content[ft_strlen(var_name)] == '=')
			return (runner->content + ft_strlen(var_name) + 1);
		runner = runner->next;
	}
	runner = exports;
	while (runner)
	{
		if (!ft_strncmp(runner->content, var_name, ft_strlen(var_name))
			&& runner->content[ft_strlen(var_name)] == '=')
			return (runner->content + ft_strlen(var_name) + 1);
		runner = runner->next;
	}
	return (NULL);
}

char	*get_var_name(char *input)
{
	int		i;
	int		j;
	char	buff[100];

	i = -1;
	j = 0;
	while (input[++i])
	{
		if (input[i] == '$' && check_in_quotes(input, i, 0, 0) != 1)
		{
			i++;
			while (input[i] && ft_isalnum(input[i]))
				buff[j++] = input[i++];
			buff[j] = '\0';
			return (ft_strdup(buff));
		}
	}
	return (NULL);
}

int	has_var_sign(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '$' && check_in_quotes(s, i, 0, 0) != 1)
			return (1);
	}
	return (0);
}
