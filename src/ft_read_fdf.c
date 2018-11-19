/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 23:07:37 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/19 01:12:50 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>
# define DEPARTY -400
# define DEPARTX 700

void		init_point(t_coord *point)
{
	point->x =DEPARTX;
	point->y = DEPARTY;
}

# define limit 256

void		set_point(t_coord *current, t_line *lst_map, t_line tete)
{
	int i;

	i = -1;
	while (++i < lst_map->size)
	{
		lst_map->point[i].alt = ft_atoi(lst_map->tab[i]) * 8;
		lst_map->point[i].x = (current->x - current->y) * cos(0.5);
		lst_map->point[i].y = (current->y - (lst_map->point[i].alt * tete.zoom) + current->x) * sin(0.5);
		if (lst_map->point[i].alt < -limit/* && lst_map->point[i].alt * 0X000004 < 0X0000FF*/)
		{
			if (abs(lst_map->point[i].alt + limit) * 0X000001 > 0X000050)
				lst_map->point[i].color = 
					abs(lst_map->point[i].alt + limit) * 0X000001;
			else
				lst_map->point[i].color = 0X0000D0;
		}
		else if (lst_map->point[i].alt < 0)
		{
			lst_map->point[i].color = 0X0000FF + 
				(lst_map->point[i].alt + limit) * (0X000100/* - 0X000001*/);
		}
		else if (lst_map->point[i].alt < limit/2)
		{
			//lst_map->point[i].color = GREEN;
			lst_map->point[i].color = lst_map->point[i].color = 0X00FFFF -
			   	lst_map->point[i].alt * 0X000002;
		}
		else if (lst_map->point[i].alt < 256)
			lst_map->point[i].color = 0X00FF00 + (lst_map->point[i].alt) * (0X010000 - 0X000100);
		else if (lst_map->point[i].alt < 256 * 2)
			lst_map->point[i].color = 0XFF0000 + (lst_map->point[i].alt - 256) * 0X000101;
		else
			lst_map->point[i].color = 0XFFFFFF;
		current->x += tete.ecart;
	}
	current->x = DEPARTX;
	current->y += tete.ecart;
}

void		calcul_point(t_line *lst_map, int ecart, float *zoom)
{
	t_coord		current;
	t_line		tete;
	
	lst_map->ecart = ecart;
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

char		**ft_read_fdf(int fd)
{
	char	*line;
	char	**tab;

	if (get_next_line(fd, &line) > 0) //si erreur de read???
	{
		tab = ft_strsplit(line, ' ');
		free (line);
		return (tab);
	}
	return (NULL);
}

# define SIZE_MINX (W_SIZEX)
# define SIZE_MINY (W_SIZEY)

t_line		*init_map(t_window window, int fd, float *zoom)
{
	t_line		*lst_map;
	t_line		*begin_lst;
	t_line		*tmp;
	int			ecart;

	lst_map = (t_line*)malloc(sizeof(t_line));
	begin_lst = lst_map;
	ecart = 100;
	//lst_map->zoom = *zoom;
	*zoom = 6;
	while ((lst_map->tab = ft_read_fdf(fd)))
	{
		lst_map->size = 0;
		while (lst_map->tab[lst_map->size]) //taille de la ligne
			lst_map->size++;
		//printf("calcul (%d * %d) %d > %d\n", ecart, lst_map->size, lst_map->size * ecart, SIZE_MINX);
		if (ecart * lst_map->size > SIZE_MINY && 
			ecart * lst_map->size > SIZE_MINX)
		ecart = ((SIZE_MINY < SIZE_MINX) ? SIZE_MINX : SIZE_MINY) / (lst_map->size + 1);
		lst_map->point = (t_coord*)malloc(sizeof(t_coord) * lst_map->size);
		lst_map->next = (t_line*)malloc(sizeof(t_line));
		tmp = lst_map;
		lst_map = lst_map->next;
	}
	printf("ecart %d\n",(int)(ecart));
	free(lst_map);
	tmp->next = NULL;
	calcul_point(begin_lst, ecart / 2, zoom);
	return (begin_lst);
}
