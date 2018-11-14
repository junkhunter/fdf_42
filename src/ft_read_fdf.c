/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:39:58 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/11/14 15:40:56 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>
# define DEPARTY 250
# define DEPARTX DEPARTY + 1500

void		init_point(t_coord *point)
{
	point->x = DEPARTX;
	point->y = DEPARTY;
	//point->b = 0.74; //45 deg
}

void      set_point(t_coord *current, t_line *lst_map, t_window window)
{
	int i = 0;

	while (i < lst_map->size)
	{
		lst_map->point[i].alt = ft_atoi(lst_map->tab[i]);
		lst_map->point[i].x = current->x - (lst_map->point[i].alt * cos(0.74)) - current->y * 1.5 * sin(1.7);
		lst_map->point[i].y = current->y - (lst_map->point[i].alt * sin(0.74)) - current->x / 2  * cos(1.7);
		if (lst_map->point[i].alt > 0)
			mlx_pixel_put(window.mlx_ptr, window.win_ptr, lst_map->point[i].x, lst_map->point[i].y, 7667971);
		else
			mlx_pixel_put(window.mlx_ptr, window.win_ptr, lst_map->point[i].x, lst_map->point[i].y, 13369103);
		//mlx_pixel_put(window.mlx_ptr, window.win_ptr, current->x, current->y, 1233151);
		i++;
		current->x += ECART;
	}
	current->x = DEPARTX;
	current->y += ECART;
}

char		**ft_read_fdf(int fd)
{
	int		i;
	char	*line;
	char	**tab;
	char	*str;
	int		j;

	j = 0;
	i = 0;
	if (get_next_line(fd, &line) > 0)
	{
		tab = ft_strsplit(line, ' ');
		free (line);
		return (tab);
	}
	return (0);
}

t_line    *init_map(t_window window)
{
	t_line		*lst_map;
	t_line		*begin_lst;
	t_coord		current;
	int			fd;
	t_line		*tmp;

	fd = open("100-6.fdf", O_RDONLY);
	init_point(&current);
	lst_map = (t_line*)malloc(sizeof(t_line));
	begin_lst = lst_map;
	lst_map->b = 0.74;
	while ((lst_map->tab = ft_read_fdf(fd)))
	{
		lst_map->size = 0;
		while (lst_map->tab[lst_map->size]) //taille de la ligne
			lst_map->size++;
		lst_map->point = (t_coord*)malloc(sizeof(t_coord) * lst_map->size);
		set_point(&current, lst_map, window);
		lst_map->next = (t_line*)malloc(sizeof(t_line));
		tmp = lst_map;
		lst_map = lst_map->next;
	}
	free(lst_map);
	tmp->next = NULL;
	return (begin_lst);
}
