/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 18:34:04 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/10/08 11:24:10 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			size;

	size = 0;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	while (n > 0)
	{
		d[size] = s[size];
		n--;
		size++;
	}
	return (d);
}
