/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 14:43:57 by bgaertne          #+#    #+#             */
/*   Updated: 2022/11/07 10:57:02 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return (&((char *)str)[i]);
		i--;
	}
	return (NULL);
}

/*
int main()
{
	char ft_test[] = "aaabaaba";
	int	ft_b = 'b';
	printf("ft_strrchr: %s\n", ft_strrchr(ft_test, ft_b));

	char test[] = "aaabaaba";
	int	b = 'b';
	printf("strrchr: %s\n", strrchr(test, b));

	// Both should output "ba"
	// Pointer on the last 'b' found
}*/
