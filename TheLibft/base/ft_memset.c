/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:38:27 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/30 16:10:53 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Sets a specified number of bytes in a memory block to a specified value.
 * 
 * @param str A pointer to the memory block that will be filled with the specified value.
 * @param c Value that will be set in each byte of the memory block.
 * @param len Length of the memory block that needs to be filled with the specified value.
 * @return A pointer to the memory block.
 */
void	*ft_memset(void *str, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)str)[i] = (unsigned char)c;
		i++;
	}
	return (str);
}

/*
int main()
{
	char test[] = "test";
	int	c = 65;
	printf("ft_memset: %s\n", ft_memset(test, c, 2));
	printf("memset: %s\n", memset(test, c, 2));

	// Both should output "AAst"
}*/