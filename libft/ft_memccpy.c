/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 21:38:19 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/10/08 09:34:06 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c,
		size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			size;

	size = 0;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	while (size < n)
	{
		d[size] = s[size];
		if (d[size] == (unsigned char)c)
		{
			size++;
			return (d + sizeof(unsigned char) * size);
		}
		size++;
	}
	return (NULL);
}
