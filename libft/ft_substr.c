/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 01:58:52 by fnieves           #+#    #+#             */
/*   Updated: 2022/04/05 19:48:34 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 ** Creates a substring from s,
 ** starting at index and max lenght of len.
 ** If index out of s , returns '\0' (with calloc for avoiding leak mem)
 ** We calculate the length of the string. If longer than the length 
 ** to be copied we reduce it to the maximum length of the string s.
 ** Now, we can copy 'len' bytes from 'start' and nullterminate '*dst'.
*/
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dst;
	int		i;
	size_t	len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen((const char *)s);
	if (len > len_s)
		len = len_s;
	if (start >= len_s)
		return ((char *)ft_calloc(sizeof(char), 1));
	i = 0;
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	while (len-- && s[i + (int)start])
	{
		dst[i] = s[i + start];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
