/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 11:46:19 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/10/07 23:15:57 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			size;

	size = -1;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (d < s)
		while (++size < len)
			d[size] = s[size];
	else
		while (len-- > 0)
			d[len] = s[len];
	return (d);
}
