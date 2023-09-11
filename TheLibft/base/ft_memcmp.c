/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:14:09 by bgaertne          #+#    #+#             */
/*   Updated: 2022/11/25 12:05:36 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return ((((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]));
		i++;
	}
	return (0);
}

/*
int	main()
{
	char ft_test1[] = "aaaaaz";
	char ft_test2[] = "aaazzz";
	printf("ft_memcmp: %d\n", ft_memcmp(ft_test1, ft_test2, 3));

	char test1[] = "aaaaaz";
	char test2[] = "aaazzz";
	printf("memcpm: %d\n", memcmp(test1, test2, 3));

	// Both should output "0"
	// as the first 3 characters are the same in each string
	// If the strings are different, the number returned does not matter.
	// Only it's sign does (negative, null or pisitive)
}*/