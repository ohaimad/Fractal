/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:45:00 by ohaimad           #+#    #+#             */
/*   Updated: 2023/01/25 20:45:25 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int ft_arrows_keys(int key, t_data *img)
{
    if(key == LEFT)
    {
        img->r_min -= 0.5;
        img->r_max -= 0.5;
    }
    else if(key == RIGHT)
    {
        img->r_max += 0.5;
        img->r_min += 0.5;
    }
    else if(key == DOWN)
     {
        img->i_min -= 0.5;
        img->i_max -= 0.5;
     }
    else if(key == UP)
     {
        img->i_max += 0.5;
        img->i_min += 0.5;
    }
    return(0);
}