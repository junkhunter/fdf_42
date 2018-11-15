/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 13:44:13 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/11/15 17:26:52 by rlucas-d         ###   ########.fr       */
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
int		main(int argc, char **argv)
{

	t_window window;
	void	*param;
	t_line	*map;
	void *img_ptr;
	char *my_image;
	
	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr,2550, 1320, "test 1");
	map = init_map(window);
	draw_sqrt(window, map);
	//my_image = 
	//mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, my_image, 0, 0);
	mlx_key_hook(window.win_ptr, deal_key, (void *)0);
	mlx_loop(window.mlx_ptr);
}
