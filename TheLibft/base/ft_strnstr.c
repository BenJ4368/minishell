/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:26:58 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/30 16:35:02 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Searches for the first occurrence of a substring `needle` in a string
 * `haystack` up to a specified length `len`.
 * 
 * @param haystack A pointer to the string in which we want to search for the `needle` string.
 * @param needle A pointer to the substring to look for.
 * @param len Maximum number of characters to search in the "haystack" string.
 * @return A pointer to the first occurrence of the `needle` string within the `haystack` string.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0' || (!haystack && len == 0))
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		if (haystack[i] == needle [j])
		{
			while (needle[j] && haystack[i + j] == needle[j]
				&& (i + j) < len)
				j++;
			if (!needle[j])
				return ((char *)&haystack[i]);
		}
		i++;
	}
	return (NULL);
}

/*
int	main()
{
	char ft_haystack[] = "She was born in a storm, with no gold, no land, no army.";
	char ft_needle[] = "storm";
	printf("%s", ft_strnstr(ft_haystack, ft_needle, 25));

	// strnstr does not exist in standard C
}*/