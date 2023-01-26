/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohaimad <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 01:03:41 by ohaimad           #+#    #+#             */
/*   Updated: 2023/01/26 02:43:34 by ohaimad          ###   ########.fr       */
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
	return (*i);
}

int	ft_atoi(char *str)
{
	int	i;
	int	res;

	res = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	ft_atoi_sign(str[i], &i);
	while (str[i++] >= '0' && str[i++] <= '9' && str[i++] != '\0')
	{
		res = res * 10;
		res = res + str[i] - '0';
		if (res > 100)
		{
			write(1, "the [0-100] range only", 22);
			exit (1);
		}
	}
	if ((res == 100 && str[i] == '.' && str[i] >= 65
			&& str[i] <= 90) || (str[i] >= 97 && str[i] <= 122))
	{
		write(1, "the [0-100] range only", 22);
		exit (1);
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
