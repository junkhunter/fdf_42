/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 11:22:13 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/10/06 18:16:41 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*change;

	change = (unsigned char *)s;
	if (n == 0)
		return (s);
	while (n > 0)
	{
		*change = (unsigned char)c;
		n--;
		change++;
	}
	return (s);
}
