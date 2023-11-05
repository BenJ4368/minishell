/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:59:55 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/30 15:49:13 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Sets a block of memory to zero.
 * 
 * @param str Pointer to the memory block that needs to be zeroed out.
 * @param n Number of bytes to be set to zero in the memory block
 * pointed to by `str`.
 */
void	ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)str)[i] = 0;
		i++;
	}
}

/*
int main()
{
	char ft_test[] = "test";
	ft_bzero(ft_test, 2);
	printf("ft_bzero: %s\n", ft_test);

	char test[] = "test";
	bzero(test, 2);
	printf("bzero: %s\n", test);
}*/
