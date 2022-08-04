/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 01:40:11 by fnieves           #+#    #+#             */
/*   Updated: 2022/08/03 16:38:24 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	error(void)
{
	write(1, "Error\n", 7);
	exit (2);
}

static int	ft_strcmp(char *s1, char *s2)
{
	while (*s1++ == *s2++)
		if (!*s1 && !*s2)
			return (0);
	return (*--s1 - *--s2);
}

static int	str_check(const char *str)
{
	char	*tmp;
	int		sign;

	sign = 0;
	tmp = (char *)str;
	if (*tmp == '-')
		sign = 1;
	if (*tmp == '-' || *tmp == '+')
		tmp++;
	if (ft_strlen(tmp) > 10 || ft_strlen(tmp) == 0)
		return (1);
	if (ft_strlen(tmp) == 10 && sign == 1 && ft_strcmp(tmp, "2147483648") > 0)
		return (1);
	if (ft_strlen(tmp) == 10 && sign == 0 && ft_strcmp(tmp, "2147483647") > 0)
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str_check(nptr))
		error();
	while (((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32) && nptr[i])
		i++;
	if ('+' == nptr[i] || '-' == nptr[i])
	{
		if ('-' == nptr[i])
			sign = -1;
		i++;
	}
	while ('0' <= nptr[i] && '9' >= nptr[i])
		res = res * 10 + ((nptr[i++] - '0'));
	return (sign * (res));
}
