/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:42:00 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/30 16:13:36 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Writes a string to a file descriptor.
 * 
 * @param s Pointer tostring to be written.
 * @param fd File descriptor.
 */
void	ft_putstr_fd(char *s, int fd)
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
	}
}
