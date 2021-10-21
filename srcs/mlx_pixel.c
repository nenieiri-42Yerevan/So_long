/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 23:11:08 by vismaily          #+#    #+#             */
/*   Updated: 2021/10/10 21:49:13 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_color(t_data *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(int *)dst);
}

void	get_my_color_png(t_map *my_map, t_mlx *my_mlx, int i, int j)
{
	if (my_map->value == 'P')
		my_map->color = get_color(&(my_mlx->p.texture), i, j);
	else if (my_map->value == 'C')
		my_map->color = get_color(&(my_mlx->c.texture), i, j);
	else if (my_map->value == 'E')
		my_map->color = get_color(&(my_mlx->e.texture), i, j);
	else if (my_map->value == 'N')
		my_map->color = get_color(&(my_mlx->n.texture), i, j);
}

void	get_my_color(t_map *my_map, t_mlx *my_mlx, int i, int j)
{
	if (my_map->value == '1')
		my_map->color = get_color(&(my_mlx->w.texture), i, j);
	else
		my_map->color = get_color(&(my_mlx->f.texture), i, j);
}
