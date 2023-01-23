/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 15:13:48 by ohaimad           #+#    #+#             */
/*   Updated: 2023/01/23 01:38:53 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void mandelbrot(t_data *img)
{
    float reel;
    float imag;
    int color;
    int i;
    int j;

    i = 0;
    j = 0;

    for(int i = 0 ; i < WIDTH ; i++)
    {
        for(int j = 0 ; j < HEIGHT ; j++)
        {
            reel = to_complexe(i);
            imag = to_complexe(j);
            color = iteration_mandelbrot(reel, imag, img);
            my_mlx_pixel_put(img, i, j, color);
        }
    }
    mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
