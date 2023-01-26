/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:43:31 by ohaimad           #+#    #+#             */
/*   Updated: 2023/01/26 05:55:43 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	tricorn(t_data *img)
{
	float	reel;
	float	imag;
	int		color;
	int		i;
	int		j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
		{
			reel = to_complexe(i, WIDTH, img->r_max, img->r_min);
			imag = to_complexe(j, HEIGHT, img->i_max, img->i_min);
			color = iteration_tricorn(reel, imag, img);
			my_mlx_pixel_put(img, i, j, color);
			j++;
		}
		i++;
	}
	mlx_clear_window(img->mlx, img->mlx_win);
	mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
