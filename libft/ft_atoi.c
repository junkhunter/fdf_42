/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 08:54:15 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/10/23 13:53:37 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	result;
	int		a;
	int		neg;
	long	count;

	a = 0;
	result = 0;
	neg = 1;
	while (str[a] == ' ' || str[a] == '\t' || str[a] == '\n' || str[a] == '\r'
			|| str[a] == '\f' || str[a] == '\v')
		a++;
	if (str[a] == '-' || str[a] == '+')
		if (str[a++] == '-')
			neg = -1;
	while (str[a] >= 48 && str[a] <= 57)
	{
		count = result;
		result = result * 10 + str[a] - '0';
		if (count && (count ^ result) < 0)
			return ((neg == 1) ? -1 : 0);
		a++;
	}
	return ((int)result * neg);
}
