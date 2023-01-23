/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 01:32:09 by ohaimad           #+#    #+#             */
/*   Updated: 2023/01/23 18:36:36 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	ft_switch(char *str)
{
	char	*mand;
	char	*jul;
	char	*tricorn;

	mand = "mandelbrot";
	jul = "julia";
	tricorn = "tricorn";
	if (ft_strncmp(str, mand, ft_strlen(str)) == 0)
		return (20);
	else if (ft_strncmp(str, jul, ft_strlen(str)) == 0)
		return (10);
	else if (ft_strncmp(str, tricorn, ft_strlen(str)) == 0)
		return (30);
	else
	{
		write (1, "please set :\n", 13);
		write (1, "1 - mandelbrot\n", 15);
		write (1, "2 - julia : x = [0 - 100] && y = [0 - 100]\n", 43);
		write (1, "3 - tricorn", 11);
		exit (1);
	}
	return (0);
}

void	ft_init(t_data *img)
{
	img->mlx = mlx_init();
	img->mlx_win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "Window");
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	img->coloring = 0;
}

int	key_shift(int key, t_data *shifting)
{
	if (key == S)
	{
		mlx_clear_window(shifting->mlx, shifting->mlx_win);
		if (shifting->coloring == 3)
			shifting->coloring = 0;
		else
			shifting->coloring++;
		if (shifting->status == 10)
			julia(shifting);
		else if (shifting->status == 20)
			mandelbrot(shifting);
		else if (shifting->status == 30)
			tricorn(shifting);
	}
	else if (key == SPACE && shifting->status == 10)
		shifting->move =! shifting->move;
	else if (key == ESP)
		ft_exit(shifting);
	return (0);
}

float	to_complexe(int a)
{
	return (((float)(4 * a) / 600) - 2);
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
	while ((reel * reel + imag * imag) < 16 && iter < 100)
	{
		r = reel;
		i = imag;
		reel = r * r - i * i + cr;
		imag = 2 * r * i + ci;
		iter++;
	}
	if (iter == 100)
		return (0x0000000);
	else
		return (ft_colors(img) * 100 / iter);
}
