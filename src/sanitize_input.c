/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:56:05 by ssalor            #+#    #+#             */
/*   Updated: 2023/11/17 11:41:52 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sanitize_input(t_data *data)
{
	int	i;

	i = -1;
	while (data->input[++i])
	{
		if (is_white_space(data->input[i])
			&& check_in_quotes(data->input, i, 0, 0) == 0)
			data->input[i] = ' ';
	}
}

int	is_white_space(char c)
{
	if (c == ' '
		|| c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r')
		return (1);
	return (0);
}

int	check_for_blank_cmd(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
	{
		if (only_white_spaces(tab[i]))
		{
			i = -1;
			while (tab[++i])
				free(tab[i]);
			free(tab);
			return (1);
		}
	}
	return (0);
}
