/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 01:27:39 by ohaimad           #+#    #+#             */
/*   Updated: 2023/01/23 17:55:25 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_exit(t_data *mlxt)
{
	mlx_destroy_image(mlxt->mlx, mlxt->img);
	mlx_destroy_window(mlxt->mlx, mlxt->mlx_win);
	exit(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	iteration_julia(float reel, float imag, t_data *img)
{
	int		iter;
	float	r;
	float	i;

	iter = 0;
	while ((reel * reel + imag * imag) < 16 && iter < 100)
	{
		r = reel;
		i = imag;
		reel = r * r - i * i + img->cr;
		imag = 2 * r * i + img->ci;
		iter++;
	}
	if (iter == 100)
		return (0x0000000);
	else
		return (ft_colors(img) * 100 / iter);
}

int	ft_map_jl(int x, int y, t_data *img)
{
	if (img->move == 1 && x >= 0 && x <= WIDTH && y >= 0 && y <= HEIGHT)
	{
		img->cr = to_complexe(x);
		img->ci = to_complexe(y);
		julia(img);
	}
	return (0);
}

int	ft_colors(t_data *img)
{
	int	color;

	if (img->coloring == 0)
		color = 0x00FFF000;
	if (img->coloring == 1)
		color = 0x000f0000;
	if (img->coloring == 2)
		color = 0x0000A170;
	if (img->coloring == 3)
		color = 0x000FFFF0;
	return (color);
}
