/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:38:27 by bgaertne          #+#    #+#             */
/*   Updated: 2022/11/10 15:38:29 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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