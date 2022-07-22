/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 18:31:59 by fnieves           #+#    #+#             */
/*   Updated: 2022/04/01 16:33:18 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 ** As we have to copy the behavior of the original funct
 ** if (!dest && !src) . It will be safer if (!dest || !src) 
 ** function copies n bytes from memory area src to memory area dst.
 ** if overlapping go to memmove.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*pdest;
	unsigned char	*psrc;
	size_t			i;

	if (!dest && !src)
		return (NULL);
	pdest = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	i = 0;
	while (n--)
	{
		pdest[i] = psrc[i];
		i++;
	}
	return ((void *)dest);
}
