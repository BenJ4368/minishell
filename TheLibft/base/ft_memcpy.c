/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:18:08 by bgaertne          #+#    #+#             */
/*   Updated: 2022/11/02 16:18:08 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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