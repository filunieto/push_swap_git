/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:30:08 by fnieves           #+#    #+#             */
/*   Updated: 2022/05/06 12:27:55 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 ** Allocates memory and copy string s into this memory.
 ** Returns the pointer with the string(ending in 0).
 ** Returns null if any memory problem.
*/
char	*ft_strdup(const char *s)
{
	char	*dest;
	int		leng_s;
	int		i;

	leng_s = ft_strlen((const char *)s);
	dest = (char *)malloc(sizeof(char) * (leng_s +1));
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return ((char *)dest);
}
