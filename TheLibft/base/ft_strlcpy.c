/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:06:42 by bgaertne          #+#    #+#             */
/*   Updated: 2022/11/06 13:32:57 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (size == 0)
		return (len);
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (len);
}

/*
int main()
{
	char ft_dest[] = "aaaaa";
	char ft_src[] = "test";
	printf("ft_strlcpy: %zu, %s\n", ft_strlcpy(ft_dest, ft_src, 4), ft_dest);

	char dest[] = "aaaaa";
	char src[] = "test";
	printf("strlcpy: %lu, %s\n", strlcpy(dest, src, 4), dest);

	// Both should output "4, tes"
	// Length of src (4), and the resulting 4-character-dest (tes\0)
}*/