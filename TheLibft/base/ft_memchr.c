/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:04:57 by bgaertne          #+#    #+#             */
/*   Updated: 2022/11/10 15:37:53 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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