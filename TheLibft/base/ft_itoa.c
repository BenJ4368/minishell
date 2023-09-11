/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:15:29 by bgaertne          #+#    #+#             */
/*   Updated: 2022/11/10 15:18:59 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	digits(long nbr)
{
	size_t	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr > 0)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

void	ft_itoa_nbr(long nbr, char *str, size_t *i)
{
	if (nbr >= 10)
	{
		ft_itoa_nbr(nbr / 10, str, i);
		ft_itoa_nbr(nbr % 10, str, i);
	}
	if (nbr < 10)
		str[(*i)++] = nbr + '0';
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	long	nbr;

	nbr = n;
	str = malloc(sizeof(char) * (digits(n) + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (nbr < 0)
	{
		str[i++] = '-';
		nbr = -nbr;
	}
	ft_itoa_nbr(nbr, str, &i);
	str[i] = '\0';
	return (str);
}

/*
int main()
{
	int ft_test = -2147483648;
	printf("ft_itoa: %s\n", ft_itoa(ft_test));
}*/