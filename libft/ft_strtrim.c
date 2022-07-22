/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnieves- <fnieves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 19:46:58 by fnieves           #+#    #+#             */
/*   Updated: 2022/04/01 17:26:24 by fnieves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* function eliminates the blank spaces at the beginning and at the end. 
if the reference to be eliminated are letters:
s1 = "Puertacasa", set = "Puerta":
newstrn = "cas"
Ft_strchr function for character at the beggining of s1 to remove.
We do the same starting from the end and decrementing.
we return the substring starting from index 0 and with the length left over
*/
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	size_t	len_s;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	len_s = ft_strlen((const char *)s1);
	while (ft_strchr(set, *(s1 + len_s - 1)) && len_s > 0)
		len_s--;
	dest = ft_substr(s1, 0, len_s);
	return (dest);
}
