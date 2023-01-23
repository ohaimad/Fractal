/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:43:31 by ohaimad           #+#    #+#             */
/*   Updated: 2023/01/23 17:43:46 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void tricorn(t_data *img)
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
            color = iteration_tricorn(reel, imag, img);
            my_mlx_pixel_put(img, i, j, color);
        }
    }
    mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
}