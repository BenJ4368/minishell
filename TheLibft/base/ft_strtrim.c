/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:32:44 by bgaertne          #+#    #+#             */
/*   Updated: 2022/11/16 15:25:44 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_getstartoffset(const char *set, const char *s1)
{
	size_t	length;
	size_t	i;

	length = ft_strlen(s1);
	i = 0;
	while (i < length)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

int	ft_getendoffset(const char *set, const char *s1)
{
	size_t	length;
	size_t	i;

	length = ft_strlen(s1);
	i = 0;
	while (i < length)
	{
		if (ft_strchr(set, s1[length - 1 - i]) == 0)
			break ;
		i++;
	}
	return (length - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	startoffset;
	size_t	endoffset;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	startoffset = ft_getstartoffset(set, s1);
	endoffset = ft_getendoffset(set, s1);
	if (endoffset <= startoffset)
		return (ft_strdup(""));
	str = malloc(sizeof(char) * (endoffset - startoffset + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, (s1 + startoffset), (endoffset - startoffset + 1));
	return (str);
}

/*
int main()
{
	char test[] = "4242I AM THE ONE WHO KNOCKS4242";
	char testset[] = "42";
	printf("ft_strtrim: %s\n", ft_strtrim(test, testset));
}*/