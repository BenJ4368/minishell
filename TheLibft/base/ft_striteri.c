/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 12:19:20 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/30 16:27:39 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Iterates through a string and applies a function to each character,
 * passing the index and character as arguments.
 * 
 * @param s A pointer to a string to iterate over and apply a function to each character.
 * @param f A function pointer to a function with the following two parameters: an unsigned int and a char pointer.
 * @return a pointer to the modified string 's'.
 */
char	*ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	i;

	if (!s || !f)
		return (NULL);
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
	return (s);
}
