/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 13:36:47 by bgaertne          #+#    #+#             */
/*   Updated: 2023/09/28 11:16:35 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

char	*ft_updt_reserve(char *reserve, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(reserve, buffer);
	free(reserve);
	return (temp);
}

char	*ft_leftover(char *reserve)
{
	int		i;
	int		j;
	char	*leftover;

	i = 0;
	while (reserve[i] && reserve[i] != '\n')
		i++;
	if (!reserve[i])
	{
		free(reserve);
		return (NULL);
	}
	leftover = ft_calloc(ft_strlen(reserve) - i + 1, sizeof(char));
	if (!leftover)
		return (NULL);
	i++;
	j = 0;
	while (reserve[i])
		leftover[j++] = reserve[i++];
	free(reserve);
	return (leftover);
}

char	*ft_line(char *reserve)
{
	int		i;
	char	*line;
	char	*temp;

	i = 0;
	if (!reserve[i])
		return (NULL);
	while (reserve[i] && reserve[i] != '\n')
		i++;
	if (reserve[i] == '\n')
		i++;
	line = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (reserve[i] && reserve [i] != '\n')
	{
		line[i] = reserve[i];
		i++;
	}
	if (reserve[i] && reserve[i] == '\n')
		line[i] = '\n';
	i++;
	temp = line;
	free(line);
	return (temp);
}

char	*ft_read_and_reserve(int fd, char *reserve)
{
	char	*buffer;
	int		bytes;

	if (!reserve)
		reserve = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			reserve = NULL;
			return (NULL);
		}
		buffer[bytes] = '\0';
		reserve = ft_updt_reserve(reserve, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (reserve);
}

char	*get_next_line(int fd)
{
	static char	*reserve;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		if (reserve)
			free(reserve);
		reserve = NULL;
		return (NULL);
	}
	reserve = ft_read_and_reserve(fd, reserve);
	if (!reserve)
	{
		free(reserve);
		return (NULL);
	}
	line = ft_line(reserve);
	reserve = ft_leftover(reserve);
	return (line);
}
