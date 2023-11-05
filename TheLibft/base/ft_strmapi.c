/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:20:26 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/30 16:31:32 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Applies a function `f` to each character of a given string, returning
 * a new string with the modified characters.
 * 
 * @param s A pointer to a constant character string
 * @param f A function pointer that takes two arguments: an `unsigned int`
 * representing the index of the character in the string, and a `char` representing the character
 * itself. The function pointed to by `f` should return a `char`.
 * 
 * @return A pointer to a newly allocated string.
 */
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	i;

	if (!s || !f)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
