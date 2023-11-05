/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:21:26 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/30 16:23:15 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Searches for a specific character in a string and returns a pointer to the
 * first occurrence of that character.
 * 
 * @param str A pointer to the string in which to search for the character.
 * @param c Character to look for.
 * @return A pointer to the first occurrence of the character in the string. NULL if not found
 */
char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&((char *)str)[i]);
		i++;
	}
	if ((char)c == str[i])
		return (&((char *)str)[i]);
	return (NULL);
}

/**
 * Used by get_next_line. Searches for a specific character in a string.
 * 
 * @param str A pointer to the string in which to search for the character.
 * @param c Character to look for.
 * @return 1 if found, 0 otherwise.
 */
int	gnl_ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (1);
		i++;
	}
	if ((char)c == str[i])
		return (1);
	return (0);
}

/*
int main()
{
	char ft_test[] = "aaabaa";
	int	ft_b = 'b';
	printf("ft_strchr: %s\n", ft_strchr(ft_test, ft_b));

	char test[] = "aaabaa";
	int	b = 'b';
	printf("strchr: %s\n", strchr(test, b));

	// Both should output "baa"
	// Pointer on the first 'b' found
}*/