/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 16:47:06 by ohaimad           #+#    #+#             */
/*   Updated: 2023/01/29 16:48:36 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	zoom(t_data *img, int key, int x, int y)
{
	if (key == ZOOM_IN)
	{
		img->r_max += x;
		img->r_min += x;
		img->i_max += y;
		img->i_min += y;
		img->r_min *= 0.6;
		img->r_max *= 0.6;
		img->i_min *= 0.6;
		img->i_max *= 0.6;
	}
	else if (key == ZOOM_OUT)
	{
		img->r_max /= 0.6;
		img->r_min /= 0.6;
		img->i_min /= 0.6;
		img->i_max /= 0.6;
		img->r_max -= x;
		img->r_min -= x;
		img->i_max -= y;
		img->i_min -= y;
	}
	return (0);
}

int	ft_mouse_zoom(int key, int x, int y, t_data *img)
{
	x = to_complexe(img->xx, WIDTH, img->r_max, img->r_min);
	y = to_complexe(img->yy, HEIGHT, img->i_max, img->i_min);
	zoom(img, key, x, y);
	if (img->status == 10)
		julia(img);
	else if (img->status == 20)
		mandelbrot(img);
	else if (img->status == 30)
		tricorn(img);
	return (0);
}
