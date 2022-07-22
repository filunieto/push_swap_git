/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 20:56:22 by fnieves           #+#    #+#             */
/*   Updated: 2022/04/01 17:26:24 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
 ** concatenate 2 strings and return the total concatenated length.
 ** 1st case:
 ** The memory space in the destination is less than its length.
 ** We do not concatenate and return source length plus
 ** the number of destination characters , dst_size.
 ** 2nd case:
 ** length in destination memory greater than the string dest:
 ** we concatenate as much as possible (always leaving a space
 ** for the null character and max dst_size)
 ** and return the sum of both strings.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	leng_dst;
	size_t	leng_src;
	size_t	i;
	size_t	limit;

	leng_dst = ft_strlen(dst);
	leng_src = ft_strlen((const char *)src);
	if (dst_size <= leng_dst)
		return (dst_size + leng_src);
	i = 0;
	limit = leng_dst;
	while (src[i] && i < (dst_size - leng_dst - 1))
		dst[limit++] = src[i++];
	dst[limit] = '\0';
	return (leng_dst + leng_src);
}
