/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 11:52:34 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/10/20 10:29:59 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	char	tmp;
	int		a;
	int		size;

	a = 0;
	size = 0;
	while (str[size])
		size++;
	size--;
	while (a <= size)
	{
		tmp = str[size];
		str[size] = str[a];
		str[a] = tmp;
		a++;
		size--;
	}
	return (str);
}
