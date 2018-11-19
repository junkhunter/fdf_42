/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:43:22 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/11/19 03:29:06 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include <mlx.h>
#include "../includes/fdf.h"

void    draw_sqrt(t_window window, t_line *lst_map)
{
	int		i;

	while (lst_map)
	{
		i = 0;
		while(i < lst_map->size)
		{
			if (i < lst_map->size - 1 && lst_map->point[i].x < W_SIZEX && lst_map->point[i].y < W_SIZEY
					&& lst_map->point[i + 1].x < W_SIZEX && lst_map->point[i + 1].y < W_SIZEY)
			{
				if (lst_map->point[i].alt <= lst_map->point[i + 1].alt)
					draw_line(lst_map->point[i], lst_map->point[i + 1], window , lst_map->ecart);
				else
					draw_line(lst_map->point[i + 1], lst_map->point[i], window , lst_map->ecart);
			}
			if (lst_map->next != NULL && lst_map->point[i].x < W_SIZEX && lst_map->point[i].y < W_SIZEY
					&& lst_map->next->point[i].x < W_SIZEX && lst_map->next->point[i].y < W_SIZEY)
			{
				if (lst_map->point[i].alt <= lst_map->next->point[i].alt)
					draw_line(lst_map->point[i], lst_map->next->point[i], window , lst_map->ecart);
				else
					draw_line(lst_map->next->point[i], lst_map->point[i], window , lst_map->ecart);
			}
			i++;
		}
		lst_map = lst_map->next;
	}
}

void		init_var_draw(t_var_draw *var, t_coord point1, t_coord point2, int *size_l)
{
	var->dx = abs(point2.x-point1.x);
	var->dy = abs(point2.y-point1.y);
	var->xincr = (point1.x < point2.x) ? 1 : -1;
	var->yincr = (point1.y < point2.y) ? 1 : -1;
	var->erreur = (var->dx > var->dy) ? var->dx / 2 : var->dy /2;
	var->e = 0;	
	*size_l = sqrt(pow(var->dx, 2) + pow(var->dy, 2));
}

void		draw_line(t_coord point1, t_coord point2, t_window window , int ecart)
{
	t_var_draw	var;
	int			color_s;
	int			size_l;

	init_var_draw(&var, point1, point2, &size_l);
	mlx_pixel_put(window.mlx_ptr, window.win_ptr, point1.x, point1.y, point1.color);
	color_s = (point2.alt > 128 || point2.alt < 0) ?
	ft_select_increment(point2) : -0X000002;
	if (var.dx > var.dy)
	{
		while ((var.e++) < var.dx)
		{
			point1.x += var.xincr;
			var.erreur += var.dy;
			if (var.erreur > var.dx)
			{
			//	if (point2.alt != point1.alt && point2.alt > -255)
			//		if (size_l <= 255 || (var.e % 2 == 0))
			//			point1.color += color_s;
				var.erreur -= var.dx;
				point1.y += var.yincr;
			}
			if (point2.alt > 256 * 2)
				point1.color = 0XFFFFFF;
			else if (point2.alt != point1.alt)
				if (size_l <= 256 || (var.e % 2))
					point1.color += color_s;
			mlx_pixel_put(window.mlx_ptr, window.win_ptr, point1.x, point1.y, point1.color);
		}
	}
	else
	{
		while (var.e++ < var.dy)
		{
			point1.y += var.yincr;
			var.erreur += var.dx;
			if (var.erreur > var.dy)
			{
		//		if (point2.alt != point1.alt && point2.alt > -255)
		//			if (size_l <= 255 || (var.e % 2 == 0))
		//				point1.color += color_s;
				var.erreur -= var.dy;
				point1.x += var.xincr;
			}
			if (point2.alt > 256 * 2)
				point1.color = 0XFFFFFF;
			else if (point2.alt != point1.alt)
				if (size_l <= 256 || (var.e % 2))
					point1.color += color_s;
			//if (point2.alt != point1.alt)
			//	point1.color += color_s;
			mlx_pixel_put(window.mlx_ptr, window.win_ptr, point1.x, point1.y, point1.color);
		}
	}
}
