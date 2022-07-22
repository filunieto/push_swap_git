/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 11:48:48 by fnieves           #+#    #+#             */
/*   Updated: 2022/04/01 17:26:24 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* 
As strchr.
We calculate the length of the string
position the pointer at the end of the string
traverse to the beginning of the string to find the character
decrementing the pointers as maximum string length
*/
char	*ft_strrchr(const char *s, int c)
{
	int		leng_s;
	char	*pts;

	leng_s = ft_strlen((const char *)(s));
	pts = (char *)(s + leng_s);
	while ((leng_s > 0) && *pts != (char)c)
	{
		pts--;
		leng_s--;
	}
	if (*pts == (char)c)
		return (pts);
	return (NULL);
}
