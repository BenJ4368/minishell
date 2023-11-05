/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:07:55 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/04 16:00:19 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Dynamically allocate a copy of given string.
 * 
 * @param src String to duplicate.
 * @return A pointer to the newly allocated string.
 */
char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	dest = malloc((i + 1) * sizeof(*dest));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{	
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/*
int	main()
{
	char ft_test[] = "test";
	printf("ft_strdup: %s\n", ft_strdup(ft_test));

	char test[] = "test";
	printf("strdup: %s\n", strdup(test));

	// Both should output "test"
}*/