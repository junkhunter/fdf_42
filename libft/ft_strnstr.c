/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 17:36:39 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/10/05 11:02:35 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	if (*s2 == '\0')
		return ((char *)s1);
	a = ft_strlen(s2);
	while (*s1 != '\0' && n-- >= a)
	{
		if (*s1 == *s2 && ft_memcmp(s1, s2, a) == 0)
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
