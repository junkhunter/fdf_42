/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:43:22 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/11/14 18:43:56 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include <mlx.h>
#include "../includes/fdf.h"

void    draw_sqrt(t_window window, t_line *lst_map)
{
	int		i;

	lst_map = init_map(window);

	while (lst_map)
	{
		i = 0;
		while(i < lst_map->size)
		{
			if (i < lst_map->size - 1)
			{
				if (lst_map->point[i].alt <= lst_map->point[i + 1].alt)
					draw_line(lst_map->point[i], lst_map->point[i + 1], window);
				else
					draw_line(lst_map->point[i + 1], lst_map->point[i], window);
			}
			if (lst_map->next != NULL)
			{
				if (lst_map->point[i].alt <= lst_map->next->point[i].alt)
					draw_line(lst_map->point[i], lst_map->next->point[i], window);
				else
					draw_line(lst_map->next->point[i], lst_map->point[i], window);
			}
			i++;
		}
		lst_map = lst_map->next;
	}
}

void		draw_line(t_coord point1, t_coord point2, t_window window)
{
	int		dx;
	int		dy;
	int		xincr;
	int		yincr;
	int		erreur;
	int		e;

	dx = abs(point2.x-point1.x);
	dy = abs(point2.y-point1.y);
	xincr = (point1.x < point2.x) ? 1 : -1;
	yincr = (point1.y < point2.y) ? 1 : -1;
	mlx_pixel_put(window.mlx_ptr, window.win_ptr, point1.x, point1.y, 16777215);
	if(dx > dy)
	{
		erreur = dx / 2;
		e = 0;
		while ((e++) < dx)
		{
			point1.x += xincr;
			erreur += dy;
			if(erreur > dx)
			{
				erreur -= dx;
				point1.y += yincr;
			}
			mlx_pixel_put(window.mlx_ptr, window.win_ptr, point1.x, point1.y, 15267121 + ((point2.alt == point1.alt) ? (point2.alt * 150) : (e * point2.alt / 1.5 * 20 - ECART)));
		}
	}
	else
	{
		erreur = dy / 2;
		e = 0;
		while (e++ < dy)
		{
			point1.y += yincr;
			erreur += dx;
			if(erreur > dy)
			{
				erreur -= dy;
				point1.x += xincr;
			}
			mlx_pixel_put(window.mlx_ptr, window.win_ptr, point1.x, point1.y, 15267121 + ((point2.alt == point1.alt) ? (point2.alt * 150) : (e * (point2.alt / 1.5) * 20 - ECART)));
		}
	}
}
