/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:44:52 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/30 16:12:22 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Writes a string followed by a newline to a specified file
 * descriptor.
 * 
 * @param s Pointer to the string to be written.
 * @param fd File descriptor.
 */
void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (s && fd > -1)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
		write(fd, "\n", 1);
	}
}
