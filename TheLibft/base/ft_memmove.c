/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:08:13 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/30 16:09:34 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Copies `n` bytes from the memory area `src` to the memory area `dest`,
 * handling overlapping memory regions correctly.
 * 
 * @param dest A pointer to the destination memory where the copied data will
 * be stored.
 * @param src A pointer to the source memory location from where the data will
 * be copied.
 * @param n Number of bytes to be copied.
 * @return A pointer to the destination memory block.
 */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (!dest && !src)
		return (NULL);
	if (dest > src)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}

/*
int	main()
{
	char ft_dest[] = "aaaaa";
	char ft_src[] = "test";
	printf("ft_memmove: %s\n", ft_memmove(ft_dest, ft_src, 3));

	char dest[] = "aaaaa";
	char src[] = "test";
	printf("memmove: %s\n", memmove(dest, src, 3));

	// Both should output "tesaa"
}*/
