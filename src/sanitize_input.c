/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sanitize_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 13:56:05 by ssalor            #+#    #+#             */
/*   Updated: 2023/10/23 14:42:37 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	sanitize_input(t_data *data)
{
	char	**tab;
	char	*new_input;s
	int		i;
	int		malloc_len;

	tab = ft_split_unquoted(data->input, ' ');
	malloc_len = 0;
	i = -1;
	while (tab[++i])
		malloc_len += ft_strlen(tab[i]) + 1;
	new_input = ft_calloc(sizeof(char), malloc_len);
	i = -1
	while (tab[++i])
		ft_strlcat(new_input, tab[i])
}
