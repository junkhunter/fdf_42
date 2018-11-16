/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:43:17 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/11/15 17:18:22 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <mlx.h>

int        deal_mouse(int a, void *param)
{
	ft_putnbr(a);
	return(0);
}

int        deal_key(int key, void *param)
{
	ft_putnbr(key);
	if (key == 53)
		exit(0);
	return (0);
}
