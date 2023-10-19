/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:47:01 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/19 11:18:14 by ssalor           ###   ########.fr       */
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
			return (runner->content);
		runner = runner->next;
	}
	return (NULL);
}

char	*expand_malloc(t_data *data, char *var_name)
{
	int		malloc_len;
	char	*var;
	char	**value_var_env;

	var = find_var(data->ms_envv, var_name);
	if (var)
	{
		malloc_len = ft_strlen(data->input)
			- 2 *(1 + ft_strlen(var_name)) + ft_strlen(var) + 1;
		value_var_env = ft_split(var, '=');
		printf("%s\n", value_var_env[1]);
	}
	else
	{
		printf("rien\n");
		malloc_len = ft_strlen(data->input) - 1 - ft_strlen(var_name) + 1;
	}
	return ((char *)malloc(sizeof(char) * malloc_len));
}

void	expand_input(t_data *data)
{
	int		i;
	int		j;
	char	**tab;
	char	*temp;
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
			(void)temp;
			tab = ft_split(data->input, '$');
			(void)tab;
		}
	}
}
