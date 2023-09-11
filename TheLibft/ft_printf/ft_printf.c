/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:13:27 by bgaertne          #+#    #+#             */
/*   Updated: 2023/01/05 14:40:29 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_process_input(const char *input, va_list args)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1])
		{
			count += ft_analyze_format(input, args, i + 1);
			i += 2;
		}
		if (input[i] != '%' && input[i])
		{
			count += ft_printchar(input[i]);
			i++;
		}
	}
	return (count);
}

int	ft_printf(const char *input, ...)
{
	int		count;
	va_list	args;

	if (!input)
		return (-1);
	va_start(args, input);
	count = 0;
	count += ft_process_input(input, args);
	va_end(args);
	return (count);
}
