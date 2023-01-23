/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 01:11:10 by ohaimad           #+#    #+#             */
/*   Updated: 2023/01/23 17:43:07 by ohaimad          ###   ########.fr       */
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
    if(ft_switch(av[1])== 10)
    {
        if (ac != 4)
            exit(1);
        img->move = 0;
        img->cr = to_complexe(ft_atoi(av[2]));
        img->ci = to_complexe(ft_atoi(av[3]));
        ft_init(img);
        julia(img);
    }
}
int	main(int ac, char **av)
{
	t_data	img;
    defin_sets(&img, av, ac);
    img.status = ft_switch(av[1]);
    mlx_hook(img.mlx_win, 17, 0, ft_exit, &img);
    mlx_hook(img.mlx_win, 6, 0, ft_map_jl, &img);
    mlx_key_hook(img.mlx_win, key_shift, &img);
	mlx_loop(img.mlx);

	return(0);
}