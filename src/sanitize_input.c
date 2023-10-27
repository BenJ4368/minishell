/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:56:05 by ssalor            #+#    #+#             */
/*   Updated: 2023/10/27 11:49:29 by ssalor           ###   ########.fr       */
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
