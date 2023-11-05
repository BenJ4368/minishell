/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:23:38 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/30 16:39:26 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Takes a string `s`, a starting index `start`, and a length `len`, and
 * returns a new substring of `s` starting from `start` and of length `len`.
 * 
 * @param s A pointer to the string from which to extract the substring.
 * @param start Index at which to start extracting the substring from the input string.
 * @param len Length of the substring that you want to extract from the string `s`.
 * @return A pointer to a newly allocated substring of the input string `s`.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
	{
		str = ft_calloc(1, sizeof(char));
		if (!str)
			return (NULL);
		return (str);
	}
	if (ft_strlen(s) - start < len)
		len = ft_strlen(s) - start;
	str = ft_calloc((len + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
int main()
{
	char s[] = "We could arrange to have you carried.";
	printf("ft_substr: %s", ft_substr(s, 0, 8));

	// Should output "We could", Null terminated.
}*/