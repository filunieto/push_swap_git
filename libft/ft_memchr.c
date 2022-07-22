/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:36:40 by fnieves           #+#    #+#             */
/*   Updated: 2022/04/01 15:27:30 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 ** Locates the first occurrence of c (as unsigned char)
 ** in string s within 'n' bytes.
 ** We do not do this as 's; will alway have a value 
 ** 's' is const so never change. It will aways have a value,
 ** thats why if we do it will give as an error
 	if (!s)  // -> this can not happen
		return (NULL);
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*pts;
	size_t			i;
	unsigned char	c_char;

	c_char = (unsigned char)c;
	pts = (unsigned char *)s;
	i = 0;
	while (n--)
	{
		if (pts[i] == c_char)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
