/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 18:31:45 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/11/01 10:57:37 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		a;
	char	*str;

	str = (char *)s;
	a = 0;
	while (str[a] != '\0' && str[a] != (char)c)
		a++;
	if (str[a] == (char)c)
		return (&str[a]);
	if (str[a] == '\0' && str[a] != (char)c)
		return (NULL);
	return (0);
}
