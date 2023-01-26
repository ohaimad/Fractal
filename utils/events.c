/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:45:00 by ohaimad           #+#    #+#             */
/*   Updated: 2023/01/26 00:12:08 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_init(t_data *img)
{
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "Window");
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->coloring = 0;
	img->r_max = 2;
	img->r_min = -2;
	img->i_max = 2;
	img->i_min = -2;
}

int	ft_exit(t_data *mlxt)
{
	mlx_destroy_image(mlxt->mlx, mlxt->img);
	mlx_destroy_window(mlxt->mlx, mlxt->mlx_win);
	exit(0);
}
