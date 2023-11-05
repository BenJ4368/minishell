/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:36:00 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/30 15:48:11 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Converts a string into an integer.
 * 
 * @param str String to convert
 * @return an integer value.
 */
int	ft_atoi(const char *str)
{
	int	i;
	int		sign;
	int		myint;

	i = 0;
	sign = 1;
	myint = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'
			|| str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		myint = (myint * 10) + (str[i] - '0');
		i++;
	}
	return (myint * sign);
}

/*
int main()
{
	char ft_test[] = "  -54";
	printf("ft_atoi: %d\n", ft_atoi(ft_test));

	char test[] = "  -54";
	printf("atoi: %d\n", atoi(test));
}*/
