/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 08:56:06 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/10/07 22:28:47 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t		size;
	size_t		a;

	a = 0;
	size = ft_strlen((char*)src);
	while (a < n)
	{
		if (a > size)
			dest[a] = '\0';
		else
			dest[a] = src[a];
		a++;
	}
	return (dest);
}
