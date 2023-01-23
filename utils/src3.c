/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 01:03:41 by ohaimad           #+#    #+#             */
/*   Updated: 2023/01/23 18:40:33 by ohaimad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_atoi_sign(char c, int *i)
{
	if (c == '+' || c == '-')
	{
		if (c == '-')
        {
			write(1, "the [0-100] range only", 22);
            exit(1);
        }
		*i = *i + 1;
	}
	return(*i);
}

int	ft_atoi(char *str)
{
	int		i;
	int		res;

	res = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	ft_atoi_sign(str[i], &i);
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		res = res * 10;
		res = res + str[i] - '0';
		i++;
        if(res > 100)
        {
            write(1, "the [0-100] range only", 22);
            exit(1);
        }
	}
    if ((res == 100 && str[i] == '.'))
    {
        write(1, "the [0-100] range only", 22);
        exit(1);
    }
	else if ((str[i] >= 65 && str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
	{
        write(1, "alphabet are not allowed", 24);
        exit(1);
    }
	return (res);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	while ((ss1[i] || ss2[i]) && i < n)
	{
		if (ss1[i] != ss2[i]) 
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

int iteration_tricorn(float reel, float imag, t_data *img)
{
    int iter;
    float r;
    float i;

    float cr = reel;
    float ci = imag;
    iter = 0;

    while ((reel * reel + imag * imag) < 16 && iter < 100)
    {
        r = reel;
        i = imag;
        reel = r * r - i * i + cr;
        imag = -2 * r * i + ci;
        iter++;
    }
    if (iter  == 100)
        return(0x0000000);
    else
        return(ft_colors(img) * 100/iter);
}