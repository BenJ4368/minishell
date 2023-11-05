/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgaertne <bgaertne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:40:43 by bgaertne          #+#    #+#             */
/*   Updated: 2023/10/30 16:20:38 by bgaertne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * Used by ft_split. Frees the memory allocated for a 2D array of strings and returns -1.
 * 
 * @param tab Array of strings that needs to be freed.
 * @param size Number of elements in the tab array.
 * @return -1.
 */
int	ft_split_nope(char **tab, int size)
{
	while (size)
	{
		free(tab[size]);
		size--;
	}
	free(tab);
	return (-1);
}

/**
 * Used by ft_split. Copies characters from `src` to `dest` until it encounters the
 * character `c` or the end of the string, and then adds a null terminator to `dest`.
 * 
 * @param dest A pointer to a character array where the extracted word will be
 * stored.
 * @param src The source string from which to extract the word.
 * @param c Character that is used as a delimiter.
 */
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

/**
 * Used by ft_split. Splits a string into words based on a delimiter and writes each word into an array.
 * 
 * @param tab Array to write in.
 * @param s A pointer to a constant character string.
 * @param c Character that is used as a delimiter.
 * @return 0 if success, and 1 otherwise.
 */
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
			if (!tab)
				return (ft_split_nope(tab, word));
			ft_split_write_word(tab[word], s + i, c);
			i += j;
			word++;
		}
	}
	return (0);
}

/**
 * Used by ft_split. Counts the number of words in a string that are separated by
 * a delimiter.
 * 
 * @param s A pointer to a constant character string.
 * @param c Character that is used as a delimiter.
 * @return The count of words in the string `s` that are separated by the character `c`.
 */
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

/**
 * Splits the string into an array of substrings based on the delimiter `c`.
 * 
 * @param s A pointer to a constant character string.
 * @param c Character used as a delimitet.
 * @return 2D array of characters (char **).
 */
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

/*
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
}*/