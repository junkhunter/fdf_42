/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:37:09 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/11/15 17:08:24 by rlucas-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fdf.h"
#include <math.h>
# define DEPARTY 150
# define DEPARTX DEPARTY + 600

void		init_point(t_coord *point)
{
	point->x =DEPARTX;
	point->y = DEPARTY;
}

void		set_point(t_coord *current, t_line *lst_map, t_window window)
{
	int i = 0;
	while (i < lst_map->size)
	{
		lst_map->point[i].alt = ft_atoi(lst_map->tab[i]);
		lst_map->point[i].x = current->x - (lst_map->point[i].alt * cos(0.74)) /*- current->y  *2 *  sin(0.74)*/;
		lst_map->point[i].y = current->y - (lst_map->point[i].alt * sin(0.74)) /*+ current->x  /8 * cos(0.74)*/;
		if (lst_map->point[i].alt > 0)
			mlx_pixel_put(window.mlx_ptr, window.win_ptr, lst_map->point[i].x, lst_map->point[i].y, 11207430);
		else
			mlx_pixel_put(window.mlx_ptr, window.win_ptr, lst_map->point[i].x, lst_map->point[i].y, 11207430);
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

t_line		*init_map(t_window window)
{
	t_line		*lst_map;
	t_line		*begin_lst;
	t_coord		current;
	int			fd;
	t_line		*tmp;

	fd = open("test/coucou.fdf", O_RDONLY);
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
