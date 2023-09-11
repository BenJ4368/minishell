/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:41:27 by bgaertne          #+#    #+#             */
/*   Updated: 2022/12/20 11:29:25 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexcount(unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr)
	{
		nbr = nbr / 16;
		i++;
	}
	return (i);
}

void	ft_printhex(unsigned int nbr, const char c)
{
	if (nbr >= 16)
	{
		ft_printhex(nbr / 16, c);
		ft_printhex(nbr % 16, c);
	}
	else
	{
		if (nbr <= 9)
			ft_printchar(nbr + '0');
		else
		{
			if (c == 'x')
				ft_printchar(nbr - 10 + 'a');
			if (c == 'X')
				ft_printchar(nbr - 10 + 'A');
		}
	}
}

int	ft_process_hex(unsigned int nbr, const char c)
{
	if (nbr == 0)
		return (ft_printchar('0'));
	else
		ft_printhex(nbr, c);
	return (ft_hexcount(nbr));
}
