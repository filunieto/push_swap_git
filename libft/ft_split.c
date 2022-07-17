/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 18:39:57 by fnieves-          #+#    #+#             */
/*   Updated: 2022/07/17 00:58:34 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*create_word(char const *s, char c)
{
	char	*word_created;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	word_created = (char *)malloc(sizeof(char) * i + 1);
	if (!word_created)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		word_created[i] = s[i];
		i++;
	}
	word_created[i] = 0;
	return (word_created);
}

static int	count_words(char const *s, char c)
{
	int		number_words;
	int		i;

	i = 0;
	number_words = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			number_words++;
		i++;
	}
	return (number_words);
}

static char	**free_array(char **array_words)
{
	int	i;

	i = 0;
	while (array_words[i])
	{
		free(array_words[i++]);
	}
	free(array_words);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**array_words;
	int		i;

	if (!s)
		return (NULL);
	array_words = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!array_words)
		return (NULL);
	while (*s && *s == c)
		s++;
	i = 0;
	while (*s)
	{
		array_words[i++] = create_word(s, c);
		if (!array_words[i - 1])
			return (free_array(array_words));
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	array_words[i] = 0;
	return (array_words);
}