/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 01:40:11 by fnieves           #+#    #+#             */
/*   Updated: 2022/07/15 19:41:14 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32) && nptr[i])
	{
		i++;
	}
	if ('+' == nptr[i] || '-' == nptr[i])
	{
		if ('-' == nptr[i])
			sign = -1;
		i++;
	}
	while ('0' <= nptr[i] && '9' >= nptr[i])
	{
		res = res * 10 + ((nptr[i] - '0'));
		i++;
	}
	return (sign * (res));
}
