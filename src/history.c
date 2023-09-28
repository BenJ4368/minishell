/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 09:46:11 by bgaertne          #+#    #+#             */
/*   Updated: 2023/09/28 11:08:48 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	init_ms_history(void)
{
	int		fd;
	char	*buffer;

	fd = open("src/.history", O_RDWR | O_CREAT, 00777);
	if (fd == -1)
		return (ms_error("Failed to open/create .history file."), 1);
	buffer = get_next_line(fd);
	while (buffer != NULL)
	{
		buffer[ft_strlen(buffer) - 1] = '\0';
		add_history(buffer);
		buffer = get_next_line(fd);
	}
	return (fd);
}

int	ms_history(char *input)
{
	int	fd;

	fd = open("src/.history", O_RDWR | O_APPEND, 00777);
	if (fd == -1)
		return (ms_error("Failed to open/create .history file."), 1);
	add_history(input);
	write(fd, input, ft_strlen(input));
	write(fd, "\n", 1);
	close (fd);
	return (0);
}
