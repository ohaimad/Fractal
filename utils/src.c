/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 01:32:09 by ohaimad           #+#    #+#             */
/*   Updated: 2023/01/30 11:30:55 by ohaimad          ###   ########.fr       */
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
	if (ft_strncmp(str, mand, ft_strlen(mand) + 1) == 0)
		return (20);
	else if (ft_strncmp(str, jul, ft_strlen(jul) + 1) == 0)
		return (10);
	else if (ft_strncmp(str, tricorn, ft_strlen(tricorn) + 1) == 0)
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

void	ft_arrows_keys(int key, t_data *img)
{
	double	dx;
	double	dy;

	dx = img->r_max - img->r_min;
	dy = img->i_max - img->i_min;
	if (key == LEFT)
	{
		img->r_max += dx * 0.2;
		img->r_min += dx * 0.2;
	}
	else if (key == RIGHT)
	{
		img->r_min -= dx * 0.2;
		img->r_max -= dx * 0.2;
	}
	else if (key == UP)
	{
		img->i_max += dy * 0.2;
		img->i_min += dy * 0.2;
	}
	else if (key == DOWN)
	{
		img->i_min -= dy * 0.2;
		img->i_max -= dy * 0.2;
	}
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
	}
	else if (key >= LEFT && key <= UP)
		ft_arrows_keys(key, shifting);
	else if (key == SPACE && shifting->status == 10)
		shifting->move =! shifting->move;
	else if (key == ESP)
		ft_exit(shifting);
	if (shifting->status == 10)
		julia(shifting);
	else if (shifting->status == 20)
		mandelbrot(shifting);
	else if (shifting->status == 30)
		tricorn(shifting);
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
