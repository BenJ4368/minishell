/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyze_format.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:29:04 by bgaertne          #+#    #+#             */
/*   Updated: 2022/12/20 11:28:44 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_analyze_format(const char *input, va_list args, int i)
{
	int	count;

	count = 0;
	if (input[i] == '%')
		count += ft_printchar('%');
	else if (input[i] == 'x' || input[i] == 'X')
		count += ft_process_hex(va_arg(args, unsigned int), input[i]);
	else if (input[i] == 'c')
		count += ft_printchar(va_arg(args, int));
	else if (input[i] == 's')
		count += ft_printstr(va_arg(args, char *));
	else if (input[i] == 'p')
		count += ft_process_pointer(va_arg(args, unsigned long long));
	else if (input[i] == 'd' || input[i] == 'i')
		count += ft_printnbr(va_arg(args, int));
	else if (input[i] == 'u')
		count += ft_process_unsint(va_arg(args, unsigned int));
	return (count);
}
