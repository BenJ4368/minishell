/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:48:35 by bgaertne          #+#    #+#             */
/*   Updated: 2022/11/08 09:31:45 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

/*
int	main()
{
	char ft_test1[] = "aaaaaz";
	char ft_test2[] = "aaazzz";
	printf("ft_strncmp: %d\n", ft_strncmp(ft_test1, ft_test2, 3));

	char test1[] = "aaaaaz";
	char test2[] = "aaazzz";
	printf("strncpm: %d\n", strncmp(test1, test2, 3));

	// Both should output "0"
	// as the first 3 characters are the same in each string
}*/