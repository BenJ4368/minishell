/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 11:47:01 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/20 13:55:02 by bgaertne         ###   ########.fr       */
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

char	*new_input(char *start_buff, char *var_name, char *end_buff, t_data *data)
{
	int		malloc_len;
	char	*var;
	char	**value_var;
	char	*new_input;

	var = find_var(data->ms_envv, var_name);
	if (var)
	{
		value_var = ft_split(var, '=');
		malloc_len = ft_strlen(start_buff) + ft_strlen(value_var[1]) + ft_strlen(end_buff) + 1;
		new_input = malloc(sizeof(char) * malloc_len);
		ft_strlcat(new_input, start_buff, 1000);
		ft_strlcat(new_input, value_var[1], 1000);
		ft_strlcat(new_input, end_buff, 1000);
	}
	else
	{
		malloc_len = ft_strlen(start_buff) + ft_strlen(end_buff) + 1;
		new_input = malloc(sizeof(char) * malloc_len);
		ft_strlcat(new_input, start_buff, 1000);
		ft_strlcat(new_input, end_buff, 1000);
	}
	free(value_var);
	return (NULL);
}

void	expand_input(t_data *data)
{
	int		i;
	int		j;
	char	start_buff[10000];
	char	buff[100];
	char	end_buff[10000];

	i = 0;
	//while (data->input[++i])
	//{
		j = 0;
		while (data->input[i] != '$' || (data->input[i] == '$'
				&& check_in_quotes(data->input, i, 0, 0) == 1))
			start_buff[j++] = data->input[i++];
		start_buff[j] = '\0';
		j = 0;
		if (data->input[i] == '$' && check_in_quotes(data->input, i, 0, 0) != 1)
		{
			i++;
			while (data->input[i] && data->input[i] != ' '
				&& data->input[i] != '$' && data->input[i] != '"')
				buff[j++] = data->input[i++];
			buff[j] = '\0';
		}
		j = 0;
		while (data->input[i])
			end_buff[j++] = data->input[i++];
		end_buff[j] = '\0';
		free(data->input);
		data->input = new_input(start_buff, buff, end_buff, data);
		//if (has_var_sign(data->input))
		//	i = -1;
	//}
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
