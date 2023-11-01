/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 15:07:55 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/01 13:38:28 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(const char **src)
{
	char	**dest;
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	dest = (char **) malloc((i + 1) * sizeof(char *));
	i = 0;
	while (src[i])
	{
		dest[i] = ft_strdup(src[i]);
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/*
int	main()
{
	char	**dupped;
	char	**tab;
	int		i = -1;

	char ft_test[] = "bonjour comment va";
	tab = ft_split(ft_test, ' ');
	dupped = ft_tabdup((const char **)tab);
	while (dupped[++i])
		printf("ft_tabdup: %s\n", dupped[i]);
}
*/
