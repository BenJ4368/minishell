/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:59:55 by bgaertne          #+#    #+#             */
/*   Updated: 2023/01/13 15:35:28 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
