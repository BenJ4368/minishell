/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:53:06 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/17 13:36:59 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	extract_redirs(t_data *data)
{
	t_ms_cmd *runner;

	runner = data->ms_cmd;
	while (runner)
	{
		
		runner = runner->next;
	}
}
