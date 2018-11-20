/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_edit_point.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:52:21 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/20 18:54:38 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>
# define DEPARTY -400
# define DEPARTX 700

#define limit 255

void        init_point(t_coord *point)
{
	point->x = DEPARTX;
	point->y = DEPARTY;
}

void		set_point(t_coord *current, t_line *lst_map, t_line tete)
{
	int i;

	i = -1;
	while (++i < lst_map->size)
	{
		lst_map->point[i].alt = ft_atoi(lst_map->tab[i]) * tete.zoom;
		//if (lst_map->point[i].alt < 0)
		//	lst_map->point[i].alt = 0;
		lst_map->point[i].x = (current->x - current->y) * cos(0.5);
		lst_map->point[i].y = (current->y - (lst_map->point[i].alt) + current->x) * sin(0.5);
		lst_map->point[i].color = ft_fix_color(lst_map->point[i]);
		current->x += tete.ecart;
	}
	current->x = DEPARTX;
	current->y += tete.ecart;
}

void        calcul_point(t_line *lst_map, int ecart, float *zoom)
{
	t_coord     current;
	t_line      tete;

	lst_map->ecart = ecart;
	*zoom = 15;
	lst_map->zoom = *zoom;
	tete = *lst_map;
	init_point(&current);
	while (lst_map)
	{
		lst_map->zoom = *zoom;
		set_point(&current, lst_map, tete);
		lst_map = lst_map->next;
	}
}
