/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_unquoted.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 10:52:52 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/23 10:55:55 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_split_nope(char **tab, int size, int flag)
{
	if (flag)
	{
		while (size)
		{
			free(tab[size]);
			size--;
		}
		free(tab);
		return (-1);
	}
	else
	{
		while (size > 0)
		{
			size--;
			free(tab[size]);
		}
		return (0);
	}
}

void	ft_split_write_word(char *dest, const char *src, char c)
{
	size_t	i;

	i = 0;
	while ((src[i] == c || src[i] == '\0') == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int	ft_split_write(char **tab, char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	word;

	word = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] == c || s[i] == '\0') == 1)
			i++;
		else
		{
			j = 0;
			while ((s[i + j] == c || s[i + j] == '\0') == 0)
				j++;
			tab[word] = (char *)malloc(sizeof(char) * (j + 1));
			if (!tab[word])
				return (ft_split_nope(tab, word, 1));
			ft_split_write_word(tab[word], s + i, c);
			i += j;
			word++;
		}
	}
	ft_split_nope(tab, word, 0);
	return (0);
}

int	ft_split_count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if ((s[i + 1] == c || s[i + 1] == '\0') == 1
			&& (s[i] == c || s[i] == '\0') == 0)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_split_count_words(s, c) + 1));
	if (!tab)
		return (NULL);
	tab[ft_split_count_words(s, c)] = 0;
	ft_split_write(tab, s, c);
	return (tab);
}


int	main()
{
	char s[] = "ooaooaoo";
	char c = 'a';
	int i;
	char **tab = ft_split(s, c);
	
	i = 0;
	while (tab[i])
	{
		printf("n=%i: %s\n", i, tab[i]);
		i++;
	}
	system("leaks a.out");
}