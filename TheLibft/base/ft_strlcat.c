/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:47:55 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/24 14:04:54 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{	
	size_t	lendest;
	size_t	lensrc;
	size_t	i;

	if (!dest)
		lendest = 0;
	else
		lendest = ft_strlen(dest);
	if (!src)
		lensrc = 0;
	else
		lensrc = ft_strlen(src);
	if (!size && !dest)
		return (lensrc);
	if (size == 0 || lendest >= size)
		return (size + lensrc);
	i = 0;
	while (src[i] && (lendest + i) < (size - 1))
	{
		dest[lendest + i] = src[i];
		i++;
	}
	dest[lendest + i] = '\0';
	return (lensrc + lendest);
}

/*
int main()
{
	char ft_dest[20] = "Valar";
	char ft_src[] = " Morghullis, Jaqen H'ghar";
	printf("ft_strlcat: %zu, %s\n", ft_strlcat(ft_dest, ft_src, 17), ft_dest);

	char	dest[20] = "Valar";
	char	src[] = " Morghullis, Jaqen H'ghar";
	printf("strlcat: %lu, %s\n", strlcat(dest, src, 17), dest);

	// Both should output "30, Valar Morghullis"
	// Initial length of dest + length of src (30),
	// and the 17 characters of the resulting string (Valar Morghullis\0)
}*/