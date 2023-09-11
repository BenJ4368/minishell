/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_unsint.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:27:53 by bgaertne          #+#    #+#             */
/*   Updated: 2022/12/20 11:30:50 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_unsint_toa(unsigned int nbr)
{
	char	*ptr;
	int		i;

	i = ft_nbrlen(nbr);
	ptr = malloc(sizeof(char) * (i + 1));
	if (!ptr)
		return (0);
	ptr[i] = '\0';
	while (nbr)
	{
		ptr[i - 1] = nbr % 10 + '0';
		nbr = nbr / 10;
		i--;
	}
	return (ptr);
}

int	ft_process_unsint(unsigned int nbr)
{
	int		count;
	char	*ptr;

	count = 0;
	if (nbr == 0)
		count = ft_printchar('0');
	else
	{
		ptr = ft_unsint_toa(nbr);
		count += ft_printstr(ptr);
		free(ptr);
	}
	return (count);
}
