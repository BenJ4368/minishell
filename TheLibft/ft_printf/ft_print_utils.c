/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 12:16:01 by bgaertne          #+#    #+#             */
/*   Updated: 2022/12/20 11:28:50 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printnbr(int nbr)
{
	int		i;
	char	*ptr;

	i = 0;
	ptr = ft_itoa(nbr);
	i = ft_printstr(ptr);
	free(ptr);
	return (i);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
		i = ft_printstr("(null)");
	else
	{
		while (str[i])
		{
			ft_printchar(str[i]);
			i++;
		}
	}
	return (i);
}
