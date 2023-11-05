/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:53:36 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/30 15:50:36 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Allocates memory and initializes it to zero.
 * 
 * @param nbelem Number of elements to allocate memory for.
 * @param size Size in bytes of each element.
 * 
 * @return A pointer to the allocated memory.
 */
void	*ft_calloc(size_t nbelem, size_t size)
{
	void	*memory;

	memory = (void *)malloc(nbelem * size);
	if (!memory)
		return (NULL);
	ft_bzero(memory, (nbelem * size));
	return (memory);
}

/*
int main()
{
	printf("ft_calloc: %s\n", ft_calloc(8539, sizeof(int)));
	printf("calloc: %s\n", calloc(8539, sizeof(int)));

	// Nothing outputs bc of bzero
}*/