/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_unquoted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssalor <ssalor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:52:52 by bgaertne          #+#    #+#             */
/*   Updated: 2023/11/24 12:44:00 by ssalor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_split_unquoted_nope(char **tab, int size)
{
	while (size)
	{
		free(tab[size]);
		size--;
	}
	free(tab);
	return (-1);
}

void	ft_split_unquoted_write_word(char *dest, const char *src, char c)
{
	size_t	i;

	i = 0;
	while (((src[i] == c && check_in_quotes(src, i, 0, 0) == 0)
			|| src[i] == '\0') == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	ft_split_unquoted_write(char **tab, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	word;

	word = 0;
	i = 0;
	while (s[i])
	{
		if (((s[i] == c && check_in_quotes(s, i, 0, 0) == 0)
				|| s[i] == '\0') == 1)
			i++;
		else
		{
			j = 0;
			while (((s[i + j] == c && check_in_quotes(s, i + j, 0, 0) == 0)
					|| s[i + j] == '\0') == 0)
				j++;
			tab[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!tab[word])
				return (ft_split_unquoted_nope(tab, word));
			ft_split_unquoted_write_word(tab[word++], s + i, c);
			i += j;
		}
	}
	return (0);
}

int	ft_split_unquoted_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (((s[i + 1] == c && check_in_quotes(s, i + 1, 0, 0) == 0)
				|| s[i + 1] == '\0') == 1
			&& ((s[i] == c && check_in_quotes(s, i, 0, 0) == 0)
				|| s[i] == '\0') == 0)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split_unquoted(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_split_unquoted_count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	tab[ft_split_unquoted_count_words(s, c)] = 0;
	ft_split_unquoted_write(tab, s, c);
	return (tab);
}
