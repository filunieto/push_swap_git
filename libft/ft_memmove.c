/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 14:04:11 by fnieves           #+#    #+#             */
/*   Updated: 2022/03/29 17:43:46 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 ** We have to verify that destination does not overlap with source.
 ** If overlaping (&dst at right of &src | dest larger than source), 
 ** we copy from the end to the beginning (right to left),
 ** to avoid losing information when copying.
 ** If they do not overlap, it is treated as memcpy,
 ** thus copying from left to right.
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*ptr;
	const unsigned char	*ptr2;

	ptr = (unsigned char *)dst;
	ptr2 = (unsigned char *)src;
	i = 0;
	if (!ptr && !ptr2)
		return (NULL);
	if (ptr2 <= ptr)
		while (++i <= len)
			ptr[len - i] = ptr2[len - i];
	else
		while (len--)
			*ptr++ = *ptr2++;
	return ((void *)dst);
}
