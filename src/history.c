/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:46:11 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/22 14:11:57 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	init_ms_history(int ms_fd)
{
	int		fd;
	char	*buffer;
	char	*history_entry;

	fd = open("/home/ubuntu/Desktop/minishell/src/.history",
	//fd = open("/local-home/bgaertne/goinfre/Minishell/src/.history",
			O_RDWR | O_CREAT, 77777);
	if (fd == -1)
		return (ms_error("Failed to open/create .history file.", ms_fd), 1);
	buffer = get_next_line(fd);
	while (buffer != NULL)
	{
		history_entry = ft_strdup(buffer);
		history_entry[ft_strlen(history_entry) - 1] = '\0';
		add_history(history_entry);
		free(history_entry);
		free(buffer);
		buffer = get_next_line(fd);
	}
	close (fd);
	return (0);
}

int	ms_history(char *input, int ms_fd)
{
	int	fd;

	fd = open("/home/ubuntu/Desktop/minishell/src/.history",
	//fd = open("/local-home/bgaertne/goinfre/Minishell/src/.history",
			O_RDWR | O_CREAT | O_APPEND, 00777);
	if (fd == -1)
		return (ms_error("Failed to open/create .history file.", ms_fd), 1);
	add_history(input);
	write(fd, input, ft_strlen(input));
	write(fd, "\n", 1);
	close (fd);
	return (0);
}
