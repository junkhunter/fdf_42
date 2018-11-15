/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 13:44:13 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/11/15 19:43:20 by rlucas-d         ###   ########.fr       */
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
	//void *img_ptr;
	void *my_image, *img2;
	int	size;
	int i;
	int a;
	int bpp;
	int *data;
	
	i = 0;
	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr,2550, 1320, "test 1");
	//map = init_map(window);
	//draw_sqrt(window, map);
	my_image = mlx_new_image(window.mlx_ptr, 2550, 100);
	img2 = mlx_new_image(window.mlx_ptr, 100, 100);
	data = (int *)mlx_get_data_addr(my_image, &bpp, &size, &a);
	printf ("%d\n", bpp);
	while (i < 2550 * 100 || (i = 0))
		data[i++] = 0X96080A;
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, my_image, 0, 0);
	data = (int *)mlx_get_data_addr(img2, &bpp, &size, &a);
	while (i < 100 * 100)
		data[i++] = 0X00FFFF;
	mlx_put_image_to_window(window.mlx_ptr, window.win_ptr, img2, 0, 0);
	printf ("destroy %d\n", mlx_destroy_image(window.mlx_ptr, img2));
	mlx_key_hook(window.win_ptr, deal_key, (void *)0);
	mlx_loop(window.mlx_ptr);
}
