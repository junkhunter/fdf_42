/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlucas-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:44:43 by rlucas-d          #+#    #+#             */
/*   Updated: 2018/11/17 23:15:14 by rhunders         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <mlx.h>

static int		ft_open(char **argv)
{
	int fd;

	if (argv[1])
		{
			if ((fd = open(argv[1], O_RDONLY)) == -1)
			{
				write(1, "<Map error>\n", 13); //ne s'affiche pas
				return (0);
			}
		}
	else
		{
			write (1, "Usage <filename>\n", 17);
			return (0);
		}
	return (fd);
}

int		main(int argc, char **argv)
{
	t_window window;
	void	*param;
	t_line	*map;
	int fd;

	if (argc > 2)
	{
		write (1, "usage <filename>\n", 17);
		return (0);
	}
	window.mlx_ptr = mlx_init();
	window.win_ptr = mlx_new_window(window.mlx_ptr, W_SIZEX, W_SIZEY, "FDF");
	if (!(fd = ft_open(argv)))
		return (0);
	if (!(map = init_map(window, fd)))
	{
		write(1, "<file error>\n", 13);
		return (0);
	}
	draw_sqrt(window, map);
	mlx_key_hook(window.win_ptr, deal_key, (void *)0);
	mlx_loop(window.mlx_ptr);
	/*my_image = mlx_new_image(window.mlx_ptr, 2550, 100);
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
	printf ("destroy %d\n", mlx_destroy_image(window.mlx_ptr, img2));*/
}
