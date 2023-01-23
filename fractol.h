/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 12:19:58 by ohaimad           #+#    #+#             */
/*   Updated: 2023/01/23 18:43:51 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <stdlib.h>

#define SPACE 49
#define ESP 53
#define S 1
#define WIDTH 600
#define HEIGHT 600

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		coloring;
    void	*mlx;
	void	*mlx_win;
	int		status;
	float	cr;
	float	ci;
	int		move;
}				t_data;

void julia(t_data *img);
int ft_exit(t_data *mlxt);
void    my_mlx_pixel_put(t_data *data, int x, int y, int color);
float to_complexe(int a);
int ft_colors(t_data *img);
int ft_map_jl(int x, int y, t_data *img);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_atoi(char *str);
size_t	ft_strlen(char *str);
int ft_switch(char *str);
void ft_init(t_data *img);
int key_shift(int key, t_data *shifting);
void mandelbrot(t_data *img);
int iteration_mandelbrot(float reel, float imag, t_data *img);
int iteration_julia(float reel, float imag, t_data *img);
int iteration_tricorn(float reel, float imag, t_data *img);
void tricorn(t_data *img);
void    defin_sets(t_data *img, char **av, int ac);
int	ft_atoi_sign(char c, int *i);

#endif