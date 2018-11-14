/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_letter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 21:27:32 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/10/16 21:51:39 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_letter(char const *s, char c)
{
	int size;

	size = 0;
	while (s[size] != c && s[size])
		size++;
	return (size);
}
