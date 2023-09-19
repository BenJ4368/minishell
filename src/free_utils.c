/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:35:06 by bgaertne          #+#    #+#             */
/*   Updated: 2023/09/19 13:55:08 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_minishell(t_data *data)
{
	int			i;

	i = -1;
	while (data->ms_env[++i])
		free(data->ms_env[i]);
	free(data->ms_env);
	free(data->raw_cmd);
	free(data->prompt);
}


void	ms_error(char *msg)
{
	printf("Error:	%s\n", msg);
	//rl_replace_line("", 0);
	//rl_on_new_line();
	//rl_redisplay();
}