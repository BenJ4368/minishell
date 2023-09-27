/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:35:06 by bgaertne          #+#    #+#             */
/*   Updated: 2023/09/27 15:01:24 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	free_minishell(t_data *data)
{
	int			i;

	i = -1;
	while (data->ms_env[++i])
		free(data->ms_env[i]);
	free(data->ms_env);
	free(data->ms_path);
	free(data->input);
	free(data->prompt);
}
