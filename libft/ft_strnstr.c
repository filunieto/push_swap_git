/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/01 00:38:48 by fnieves           #+#    #+#             */
/*   Updated: 2022/03/23 12:00:30 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!(*little))
		return ((char *)big);
	while (*big && len)
	{
		i = 0;
		while (big[i] == little[i] && i < len)
		{
			if (!(little[i + 1]))
				return ((char *)big);
			i++;
		}
		big++;
		len--;
	}
	return (NULL);
}
