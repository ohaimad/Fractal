/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 01:27:39 by ohaimad           #+#    #+#             */
/*   Updated: 2023/01/30 15:12:38 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	iteration_julia(float reel, float imag, t_data *img)
{
	int		iter;
	float	r;
	float	i;

	iter = 0;
	while ((reel * reel + imag * imag) < 4 && iter < 100)
	{
		r = reel;
		i = imag;
		reel = r * r - i * i + img->cr;
		imag = 2 * r * i + img->ci;
		iter++;
	}
	if (iter == 100)
		return (0x0000000);
	else if (iter == 0)
		return (ft_colors(img));
	else
		return (ft_colors(img) * 100 >> iter);
}

int	ft_map_jl(int x, int y, t_data *img)
{
	img->yy = y;
	img->xx = x;
	if (img->move == 1 && x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
	{
		img->cr = to_complexe(x, WIDTH, img->r_max, img->r_min);
		img->ci = to_complexe(y, HEIGHT, img->i_max, img->i_min);
		julia(img);
	}
	return (0);
}

int	iteration_tricorn(float reel, float imag, t_data *img)
{
	int		iter;
	float	r;
	float	i;
	float	cr;
	float	ci;

	cr = reel;
	ci = imag;
	iter = 0;
	while ((reel * reel + imag * imag) < 4 && iter < 100)
	{
		r = reel;
		i = imag;
		reel = r * r - i * i + cr;
		imag = -2 * r * i + ci;
		iter++;
	}
	if (iter == 100)
		return (0x0000000);
	else if (iter == 0)
		return (ft_colors(img));
	else
		return (ft_colors(img) * 100 >> iter);
}

int	iteration_mandelbrot(float reel, float imag, t_data *img)
{
	int		iter;
	float	r;
	float	i;
	float	cr;
	float	ci;

	cr = reel;
	ci = imag;
	iter = 0;
	while ((reel * reel + imag * imag) < 4 && iter < 100)
	{
		r = reel;
		i = imag;
		reel = r * r - i * i + cr;
		imag = 2 * r * i + ci;
		iter++;
	}
	if (iter == 100)
		return (0x0000000);
	else if (iter == 0)
		return (ft_colors(img));
	else
		return (ft_colors(img) * 100 >> iter);
}
