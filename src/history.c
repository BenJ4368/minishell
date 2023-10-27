/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:46:11 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/27 14:07:50 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	init_ms_history(void)
{
	int		fd;
	char	*buffer;
	char	*history_entry;

	fd = open("/local-home/ssalor/Desktop/minishell/src/.history", O_RDWR | O_CREAT, 77777);
	if (fd == -1)
		return (ms_error("Failed to open/create .history file."), 1);
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

int	ms_history(char *input)
{
	int	fd;

	fd = open("/local-home/ssalor/Desktop/minishell/src/.history", O_RDWR | O_APPEND, 00777);
	if (fd == -1)
		return (ms_error("Failed to open/create .history file."), 1);
	add_history(input);
	write(fd, input, ft_strlen(input));
	write(fd, "\n", 1);
	close (fd);
	return (0);
}
