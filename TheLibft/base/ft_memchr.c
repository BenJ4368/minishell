/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:04:57 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/30 16:04:09 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Searches for a specific character in the `n` first bytes a given memory block and returns a
 * pointer to the first occurrence of that character, or NULL if it is not found.
 * 
 * @param str Pointer to the memory block.
 * @param c Character to look for.
 * @param n Number of bytes to search.
 * 
 * @return A pointer to the first occurrence of the character 'c', or NULL if not found.
 */
void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)str)[i] == (unsigned char)c)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}

/*
int main()
{
	char ft_str[] = "aaabaa";
	int ft_b = 'b';
	printf("ft_memchr: %p\n", ft_memchr(ft_str, ft_b, 4));

	char str[] = "aaabaa";
	int b = 'b';
	printf("memchr: %p\n", memchr(str, b, 4));
}*/