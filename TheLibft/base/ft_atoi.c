/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 14:36:00 by bgaertne          #+#    #+#             */
/*   Updated: 2022/11/06 14:36:00 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(char c)
{
	if (c == ' '
		|| c == '\f'
		|| c == '\n'
		|| c == '\r'
		|| c == '\t'
		|| c == '\v')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	int		myint;

	i = 0;
	sign = 1;
	myint = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
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
