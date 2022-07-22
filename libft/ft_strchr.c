/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 01:07:00 by fnieves           #+#    #+#             */
/*   Updated: 2022/03/28 21:06:46 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** We look for charcater c in the string s. 
** returns the pointer to the first position found.
** Null if not found.
** if char = 0: returns the last position of s (0).
*/
char	*ft_strchr(const char *s, int c)
{
	char	*pts;

	pts = (char *)(s);
	while (*pts)
	{
		if (*pts == (char)c)
			return (pts);
		pts++;
	}
	if (!(char)c)
		return (pts);
	return (NULL);
}
