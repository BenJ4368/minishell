/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:11:10 by bgaertne          #+#    #+#             */
/*   Updated: 2023/02/16 16:52:12 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>
# include <unistd.h>
# include "../base/libft.h"

// get_next_line.c
char	*ft_updt_reserve(char *reserve, char *buffer);
char	*get_next_line(int fd);
char	*ft_read_and_reserve(int fd, char *reserve);
char	*ft_line(char *reserve);
char	*ft_leftover(char *reserve);

#endif