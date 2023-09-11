/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:26:58 by bgaertne          #+#    #+#             */
/*   Updated: 2022/11/06 13:26:58 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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