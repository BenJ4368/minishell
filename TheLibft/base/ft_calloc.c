/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:53:36 by bgaertne          #+#    #+#             */
/*   Updated: 2022/11/06 14:53:36 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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