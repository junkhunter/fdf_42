/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 18:56:36 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/10/12 18:39:14 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		a;
	char	*str;

	str = (char *)s;
	a = ft_strlen(s);
	if (!(char)c)
		return (str + a);
	a--;
	while (str[a] != (char)c && str[a] && a > 0)
		a--;
	if (str[a] == (char)c)
		return (str + a);
	return (NULL);
}
