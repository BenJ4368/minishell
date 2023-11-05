/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 08:52:19 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/30 16:27:29 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Concatenates two strings and returns a new string that contains the
 * combined contents of the input strings.
 * 
 * @param s1 A pointer to a constant character string. Head of the concatenation.
 * @param s2 A pointer to a constant character string. Tail of the concatenation.
 * @return Spointer to a newly allocated string.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

/*
int main()
{
	char s1[] = "Fire";
	char s2[] = " and Blood";
	printf("ft_strjoin: %s\n",ft_strjoin(s1, s2));
}*/