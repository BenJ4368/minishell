/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:47:01 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/13 13:00:00 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*find_var(t_ms_list *ms_envv, char *var_name)
{
	t_ms_list	*runner;

	runner = ms_envv;
	while (runner)
	{
		if (!ft_strncmp(runner->content, var_name, ft_strlen(var_name))
				&& runner->content[ft_strlen(var_name)] == '=')
		{
			printf("%s\n", runner->content);
			return (NULL);
		}
		runner = runner->next;
	}
	return (NULL);
}

void	expand_malloc(t_data *data, char *var_name)
{
	int		malloc_len;
	char	*var;

	var = find_var(data->ms_envv, var_name);
	(void)var;
	malloc_len = ft_strlen(data->input) - ft_strlen(var_name);
	(void)malloc_len;
}

void	expand_input(t_data *data)
{
	int		i;
	int		j;
	char	buffer[100];

	i = -1;
	while (data->input[++i])
	{
		j = 0;
		if (data->input[i] == '$' && check_in_quotes(data->input, i, 0, 0) != 1)
		{
			i++;
			while (data->input[i] && data->input[i] != ' '
				&& data->input[i] != '$' && data->input[i] != '"')
				buffer[j++] = data->input[i++];
			buffer[j] = '\0';
			expand_malloc(data, buffer);
		}
	}
	printf("%s\n", buffer);
}
