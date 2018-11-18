/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 10:43:22 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/11/18 02:21:40 by rhunders         ###   ########.fr       */
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
			if (i < lst_map->size - 1)
			{
				if (lst_map->point[i].alt <= lst_map->point[i + 1].alt)
					draw_line(lst_map->point[i], lst_map->point[i + 1], window , lst_map->ecart);
				else
					draw_line(lst_map->point[i + 1], lst_map->point[i], window , lst_map->ecart);
			}
			if (lst_map->next != NULL)
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

void		init_var_draw(t_var_draw *var, t_coord point1, t_coord point2)
{
	var->dx = abs(point2.x-point1.x);
	var->dy = abs(point2.y-point1.y);
	var->xincr = (point1.x < point2.x) ? 1 : -1;
	var->yincr = (point1.y < point2.y) ? 1 : -1;
	var->erreur = (var->dx > var->dy) ? var->dx / 2 : var->dy /2;
	var->e = 0;	
}

void		draw_line(t_coord point1, t_coord point2, t_window window , int ecart)
{
	t_var_draw	var;
	int			color_s;

	//printf("color2 = %#06X\ncolor1 = %#06X\ncolor_s = %#06X\n", point2.color, point1.color,color_s);
	init_var_draw(&var, point1, point2);
	color_s =  (point2.color - point1.color) / ((var.dx + var.dy) ? var.dx + var.dy : 1);
	mlx_pixel_put(window.mlx_ptr, window.win_ptr, point1.x, point1.y, point1.color);
	//mlx_string_put(window.mlx_ptr, window.win_ptr, 15, 30, point1.color, "bonjour");
	if (var.dx > var.dy)
	{
		while ((var.e++) < var.dx)
		{
			point1.x += var.xincr;
			var.erreur += var.dy;
			if (var.erreur > var.dx)
			{
				var.erreur -= var.dx;
				point1.y += var.yincr;
			}
			if (point2.alt != point1.alt)
				point1.color += /*0X001100*/color_s;
			mlx_pixel_put(window.mlx_ptr, window.win_ptr, point1.x, point1.y, point1.color);
		}
	}
	else
	{
		while (var.e++ < var.dy)
		{
			point1.y += var.yincr;
			var.erreur += var.dx;
			if(var.erreur > var.dy)
			{
				var.erreur -= var.dy;
				point1.x += var.xincr;
			}
			if (point2.alt != point1.alt)
				point1.color += /*0X001100;*/color_s;/*(var.e * 15 * (point2.alt / 1.5)) - ecart * 50;*/
			mlx_pixel_put(window.mlx_ptr, window.win_ptr, point1.x, point1.y, point1.color);
		}
	}
}
