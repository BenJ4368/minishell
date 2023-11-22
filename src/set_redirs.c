/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 11:36:07 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/21 14:13:16 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	set_redir_output(t_ms_cmd *node, int i)
{
	(void)node;
	(void)i;
	printf("redir_ouput\n");
}

void	set_redir_output_append(t_ms_cmd *node, int i)
{
	(void)node;
	(void)i;
	printf("redir_ouput_append\n");
}

void	set_redir_input(t_ms_cmd *node, int i)
{
	(void)node;
	(void)i;
	printf("redir_input\n");
}

void	set_redir_heredoc(t_ms_cmd *node, int i)
{
	(void)node;
	(void)i;
	printf("redir_heredoc\n");
}
