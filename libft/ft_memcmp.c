/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 23:58:43 by fnieves           #+#    #+#             */
/*   Updated: 2022/04/01 16:45:32 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*pts1;
	unsigned char	*pts2;
	size_t			i;

	i = 0;
	pts1 = (unsigned char *)s1;
	pts2 = (unsigned char *)s2;
	while (n--)
	{
		if (pts1[i] != pts2[i])
		{
			return (pts1[i] - pts2[i]);
		}
		i++;
	}
	return (0);
}
