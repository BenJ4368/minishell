/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_on_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:46:05 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/30 14:55:11 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	split_on_pipe(t_data *data)
{
	int		i;
	char	**tab_pipe;

	i = 0;
	tab_pipe = ft_split_unquoted(data->input, '|');
	while (tab_pipe[i])
	{
		printf("%s\n", tab_pipe[i]);
		i++;
	}
}
