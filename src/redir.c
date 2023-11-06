/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:53:06 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/06 13:43:31 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	redir_pipe(t_data *data)
{
	int	pipefd[2];

	pipe(pipefd);

}

int	extract_redir(t_ms_cmd *cmd, t_data *data)
{
	

}
