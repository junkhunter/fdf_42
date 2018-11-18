/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhunders <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 23:07:37 by rhunders          #+#    #+#             */
/*   Updated: 2018/11/18 02:25:09 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <math.h>
# define DEPARTY -300
# define DEPARTX 800

void		init_point(t_coord *point)
{
	point->x =DEPARTX;
	point->y = DEPARTY;
}

void		set_point(t_coord *current, t_line *lst_map, t_window window)
{
	int i;

	i = -1;
	lst_map->point = (t_coord*)malloc(sizeof(t_coord) * lst_map->size);
	while (++i < lst_map->size)
	{
		lst_map->point[i].alt = ft_atoi(lst_map->tab[i]);
		lst_map->point[i].x = (current->x - current->y) * cos(0.5);
		lst_map->point[i].y = (current->y - (lst_map->point[i].alt * 3) + current->x) * sin(0.5);
		lst_map->point[i].color = 0X2F00F0 + ((lst_map->point[i].alt) * 0X001100);
		current->x += lst_map->ecart;
	}
	current->x = DEPARTX;
	current->y += lst_map->ecart;
}

void		calcul_point(t_line *lst_map, t_window window, int ecart)
{
	t_coord		current;

	init_point(&current);
	while (lst_map)
	{
		lst_map->ecart = ecart;
		set_point(&current, lst_map, window);
		lst_map = lst_map->next;
	}
}

char		**ft_read_fdf(int fd)
{
	char	*line;
	char	**tab;
	int		a;

	if ((a = get_next_line(fd, &line)) > 0) //si erreur de read???
	{
		tab = ft_strsplit(line, ' ');
		free (line);
		return (tab);
	}
	return (0);
}

# define SIZE_MINX (W_SIZEX - DEPARTX * 2)
# define SIZE_MINY (W_SIZEY - DEPARTY * 2)

t_line		*init_map(t_window window, int fd)
{
	t_line		*lst_map;
	t_line		*begin_lst;
	t_line		*tmp;
	int			ecart;

	lst_map = (t_line*)malloc(sizeof(t_line));
	begin_lst = lst_map;
	ecart = 100;
	while ((lst_map->tab = ft_read_fdf(fd)))
	{
		lst_map->zoom = 10;
		lst_map->size = 0;
		while (lst_map->tab[lst_map->size]) //taille de la ligne
			lst_map->size++;
		printf("calcul (%d * %d) %d > %d\n", ecart, lst_map->size, lst_map->size * ecart, SIZE_MINX);
		if (ecart * lst_map->size > SIZE_MINX)
			ecart = SIZE_MINY / (lst_map->size + 1);
		//while (ecart * (lst_map->size - 1) + (DEPARTY * 2) > W_SIZEY)
		//	ecart--;
		lst_map->next = (t_line*)malloc(sizeof(t_line));
		tmp = lst_map;
		lst_map = lst_map->next;
	}
	printf("ecart %d\n",(int)(ecart));
	free(lst_map);
	tmp->next = NULL;
	calcul_point(begin_lst, window, ecart);
	return (begin_lst);
}
