/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:39:57 by fnieves-          #+#    #+#             */
/*   Updated: 2022/04/05 19:30:19 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 ** Function count_words (assuming c +=' ')
 ** 2 conditions:
 ** it will add a word when it reaches the end of the string
 **  and the previous character is not a null character (case if s != "")
 ** Or if it reaches the character c and
 ** the preceding character is not the character c.
 ** Function create_word: receive each time a pointer
 ** to the beggining of the next word and calculate lenght till end of word
 ** Use this index for allocating memory and copy nullterminating.
*/
static char	*create_word(char const *s, char c)
{
	char	*dest;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	dest = (char *)malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	count_words(char const *s, char c)
{
	int	words_number;
	int	i;

	i = 0;
	words_number = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			words_number++;
		i++;
	}
	return (words_number);
}

char	**ft_split(char const *s, char c)
{
	char	**array_words;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	array_words = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!array_words)
		return (NULL);
	while (*s && *s == c)
		s++;
	while (*s)
	{
		array_words[i++] = create_word(s, c);
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	array_words[i] = 0;
	return (array_words);
}
