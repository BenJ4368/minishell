/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 13:18:08 by bgaertne          #+#    #+#             */
/*   Updated: 2023/02/14 14:03:01 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "../base/libft.h"

//	ft_printf.c
int		ft_printf(const char *input, ...);
int		ft_process_input(const char *input, va_list	args);
int		ft_printchar(char c);

//	ft_analyze_format.c
int		ft_analyze_format(const char *input, va_list args, int i);

//	ft_process_hex.c
int		ft_process_hex(unsigned int nbr, const char c);
void	ft_printhex(unsigned int nbr, const char c);
int		ft_hexcount(unsigned int nbr);

//	ft_print_utils.c
int		ft_printstr(char *str);
int		ft_printnbr(int nbr);

//	ft_process_pointer.c
int		ft_process_pointer(unsigned long long ptr);
void	ft_printptr(uintptr_t ptr);
int		ft_ptrlen(uintptr_t ptr);

//	ft_process_unsint.c
int		ft_process_unsint(unsigned int nbr);
char	*ft_unsint_toa(unsigned int nbr);
int		ft_nbrlen(unsigned int nbr);

#endif