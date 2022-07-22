/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 17:04:27 by fnieves           #+#    #+#             */
/*   Updated: 2022/03/28 21:44:36 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 ** Writes "n" bytes of value c 
 ** (as unsigned char) to the string 's'.
*/
void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*pts;

	pts = (unsigned char *)s;
	while (n--)
	{
		*pts++ = (unsigned char)c;
	}
	return ((unsigned char *)s);
}
