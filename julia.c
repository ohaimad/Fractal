/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:53:33 by ohaimad           #+#    #+#             */
/*   Updated: 2023/01/23 01:31:14 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <mlx.h>
#define WIDTH 600
#define HEIGHT 600


void julia(t_data *img)
{
    float reel;
    float imag;
    int color;

    for(int i =0 ; i < WIDTH ; i++)
    {
        for(int j = 0 ; j < HEIGHT ; j++)
        {
            reel = to_complexe(i);
            imag = to_complexe(j);
            color = iteration_julia(reel, imag, img);
            my_mlx_pixel_put(img, i, j, color);
        }
    }
    mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}
