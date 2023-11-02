/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:47:01 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/02 15:45:12 by bgaertne         ###   ########.fr       */
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

void	expand_input(t_data *data)
{
	char	*var_name;
	char	*var_value;
	char	*new_input;
	int		i;
	int		j;

	i = -1;
	while (data->input[++i])
	{
		var_name = get_var_name(data->input);
		if (!var_name)
			return ;
		var_value = get_var_value(data->ms_envv, data->exports, var_name);
		if (var_value)
			new_input = ft_calloc(ft_strlen(data->input) + ft_strlen(var_value)
					- ft_strlen(var_name), sizeof(char));
		else
			new_input = ft_calloc(ft_strlen(data->input) - ft_strlen(var_name), sizeof(char));
		j = 0;
		while (data->input[i] != '$' || (data->input[i] == '$'
			&& check_in_quotes(data->input, i, 0, 0) == 1))
			new_input[j++] = data->input[i++];
		i++;
		if (var_value)
		{
			ft_strlcat(new_input, var_value, ft_strlen(new_input) + ft_strlen(var_value) + 1);
			j += ft_strlen(var_value);
		}
		i += ft_strlen(var_name);
		while (data->input[i])
			new_input[j++] = data->input[i++];
		free(data->input);
		data->input = NULL;
		data->input = new_input;
		free(var_name);
		if (has_var_sign(data->input))
			i = -1;
	}
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
