/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_input_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:51:36 by ssalor            #+#    #+#             */
/*   Updated: 2023/11/24 15:15:47 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	expand_input1(int j, char *new_input, char *var_value)
{
	ft_strlcat(new_input, var_value, ft_strlen(new_input)
		+ ft_strlen(var_value) + 1);
	j += ft_strlen(var_value);
	return (j);
}

char	*expand_input2(t_data *data, char *var_value, char *var_name)
{
	char	*new_input;

	if (var_value)
		new_input = ft_calloc(ft_strlen(data->input) + ft_strlen(var_value)
				- ft_strlen(var_name), sizeof(char));
	else
		new_input = ft_calloc(ft_strlen(data->input)
				- ft_strlen(var_name), sizeof(char));
	return (new_input);
}

void	expand_input3(t_data *data, char *new_input, char *var_name)
{
	free(data->input);
	data->input = new_input;
	free(var_name);
}

void	expand_input(t_data *data, int i, int j)
{
	char	*var_name;
	char	*var_value;
	char	*new_input;

	while (data->input[++i])
	{
		var_name = get_var_name(data->input);
		if (!var_name)
			return ;
		var_value = get_var_value(data->ms_envv, data->exports, var_name);
		new_input = expand_input2(data, var_value, var_name);
		while (data->input[i] != '$' || (data->input[i] == '$'
				&& check_in_quotes(data->input, i, 0, 0) == 1))
			new_input[j++] = data->input[i++];
		i++;
		if (var_value)
			j = expand_input1(j, new_input, var_value);
		i += ft_strlen(var_name);
		while (data->input[i])
			new_input[j++] = data->input[i++];
		expand_input3(data, new_input, var_name);
		if (has_var_sign(data->input))
			i = -1;
	}
}
