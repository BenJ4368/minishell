/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:01:44 by bgaertne          #+#    #+#             */
/*   Updated: 2022/12/20 11:29:54 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrlen(uintptr_t ptr)
{
	int	i;

	i = 0;
	while (ptr)
	{
		ptr = ptr / 16;
		i++;
	}
	return (i);
}

void	ft_printptr(uintptr_t ptr)
{
	if (ptr >= 16)
	{
		ft_printptr(ptr / 16);
		ft_printptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_printchar(ptr + '0');
		else
			ft_printchar(ptr - 10 + 'a');
	}
}

int	ft_process_pointer(unsigned long long ptr)
{
	int	count;

	count = 0;
	count += ft_printstr("0x");
	if (ptr == 0)
		count += ft_printchar('0');
	else
	{
		ft_printptr(ptr);
		count += ft_ptrlen(ptr);
	}
	return (count);
}
