/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 18:17:05 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/10/18 15:26:53 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*str;
	int		a;

	a = 0;
	if (!s || !f || !(str = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[a])
	{
		str[a] = f(s[a]);
		a++;
	}
	return (str);
}
