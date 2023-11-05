/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:18:08 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/30 16:08:28 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies a specified number of bytes from the source memory location to the
 * destination memory location.
 * 
 * @param dest A pointer to the destination memory where the copied data will
 * be stored.
 * @param src A pointer to the source memory location from where the data will
 * be copied.
 * @param n Number of bytes to be copied.
 * 
 * @return A pointer to the destination memory block.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*
int main()
{
	char ft_src[] = "test";
	char ft_dest[] = "aaaaa";
	ft_memcpy(ft_dest, ft_src, 3);
	printf("ft_memcpy: %s\n", ft_dest);

	char src[] = "test";
	char dest[] = "aaaaa";
	memcpy(dest, src, 3);
	printf("memcpy: %s\n", dest);

	// Both should output "tesaa"
}*/