/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 01:11:10 by ohaimad           #+#    #+#             */
/*   Updated: 2023/01/25 20:13:01 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    defin_sets(t_data *img, char **av, int ac)
{
    if(ft_switch(av[1]) == 20)
    {
        if (ac != 2)
            exit(1);
        ft_init(img);
        mandelbrot(img);
    }
    if(ft_switch(av[1]) == 30)
    {
        if (ac != 2)
            exit(1);
        ft_init(img);
        tricorn(img);
    }
    if(ft_switch(av[1]) == 10)
    {
        if (ac != 4)
            exit(1);
        img->move = 0;
        img->r_max = 2;
        img->r_min = -2;
        img->i_max = 2;
        img->i_min = -2;
        img->cr = to_complexe(ft_atoi(av[2]), 100, img->r_max, img->r_min);
        img->ci = to_complexe(ft_atoi(av[3]), 100, img->i_max, img->i_min);
        ft_init(img);
        julia(img);
    }
}
int	main(int ac, char **av)
{
	t_data	img;
    if(ac == 1)
        exit(1);
    defin_sets(&img, av, ac);
    img.status = ft_switch(av[1]);
    mlx_hook(img.mlx_win, 17, 0, ft_exit, &img);
    mlx_hook(img.mlx_win, 6, 0, ft_map_jl, &img);
    mlx_key_hook(img.mlx_win, key_shift, &img);
	mlx_loop(img.mlx);

	return(0);
}