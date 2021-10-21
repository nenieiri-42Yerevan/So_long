/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 23:49:19 by vismaily          #+#    #+#             */
/*   Updated: 2021/10/18 22:40:00 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	put_element_1(t_mlx *my_mlx, size_t j, size_t i)
{
	if (my_mlx->my_map.value == 'P' || my_mlx->my_map.value == 'C' || \
			my_mlx->my_map.value == 'E' || my_mlx->my_map.value == 'N')
	{
		get_my_color_png(&(my_mlx->my_map), my_mlx, j, i);
		if ((my_mlx->my_map.color & 0xFF000000) == 0xFF000000)
			return (1);
		put_pixel(&(my_mlx->main_img), my_mlx->cub_width * my_mlx->my_map.j + \
		j, my_mlx->cub_height * my_mlx->my_map.i + i, my_mlx->my_map.color);
	}
	return (0);
}

static int	put_element(t_mlx *my_mlx)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < my_mlx->cub_height)
	{
		j = -1;
		while (++j < my_mlx->cub_width)
		{
			get_my_color(&(my_mlx->my_map), my_mlx, j, i);
			put_pixel(&(my_mlx->main_img), my_mlx->cub_width * \
					my_mlx->my_map.j + j, my_mlx->cub_height * \
					my_mlx->my_map.i + i, my_mlx->my_map.color);
			if (put_element_1(my_mlx, j, i) == 1)
				continue ;
		}
	}
	return (0);
}

int	put_map(t_mlx *my_mlx)
{
	my_mlx->my_map.i = -1;
	while (++(my_mlx->my_map.i) < my_mlx->my_map.map_height)
	{
		my_mlx->my_map.j = -1;
		while (++(my_mlx->my_map.j) < my_mlx->my_map.map_width)
		{
			my_mlx->my_map.value = \
				(my_mlx->my_map.map)[my_mlx->my_map.i][my_mlx->my_map.j];
			if (my_mlx->my_map.value == 'P')
			{
				my_mlx->my_map.p_i = my_mlx->my_map.i * my_mlx->cub_height;
				my_mlx->my_map.p_j = my_mlx->my_map.j * my_mlx->cub_width;
			}
			put_element(my_mlx);
		}
	}
	return (0);
}
