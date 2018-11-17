/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:08:52 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/11/17 17:27:14 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include <mlx.h>
#include "../includes/fdf.h"

void   ft_color(t_line *lst_map)
{
	int i;
	int base;
	int a;

	a = 10;
	base = 5373978;
	while (lst_map)
	{
		i = 0;
		while (i < lst_map->size)
		{
			a = 10;
			if (lst_map->point[i].alt <= lst_map->point[i + 1].alt) //augmente
			{
				lst_map->point[i].color = base + (a * (lst_map->point[i].alt *150));
				a += 2;
			}
			if (lst_map->point[i].alt == lst_map->point[i + 1].alt) //stable
				lst_map->point[i].color = base + (lst_map->point[i].alt * 150);
			if (lst_map->point[i].alt >= lst_map->point[i + 1].alt)
			{
				lst_map->point[i].color = base - (a * (lst_map->point[i].alt * 150));
				a -= 2;
			}
			i++;
		}
		lst_map = lst_map->next;
	}
}
