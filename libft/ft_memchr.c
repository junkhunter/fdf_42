/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 14:07:34 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/10/22 12:30:04 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*d;
	size_t			a;

	a = 0;
	d = (unsigned char *)s;
	while (a < n)
	{
		if (d[a] == (unsigned char)c)
			return (d + sizeof(char) * a);
		else
			a++;
	}
	return (NULL);
}
