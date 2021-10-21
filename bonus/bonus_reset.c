/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_reset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 22:23:38 by vismaily          #+#    #+#             */
/*   Updated: 2021/10/10 23:40:42 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_free(t_map my_map)
{
	size_t	i;

	i = -1;
	while (++i < my_map.map_height)
		free(my_map.map[i]);
	free(my_map.map);
}

int	bonus_reset(t_mlx *my_mlx, int *counter)
{
	char	**map_2;

	map_free(my_mlx->my_map);
	map_copy(my_mlx, &(my_mlx->my_map.map_initial), &map_2);
	my_mlx->my_map.map = map_2;
	mlx_destroy_image(my_mlx->mlx, my_mlx->main_img.img);
	my_mlx->main_img.img = mlx_new_image(my_mlx->mlx, SCREEN_WIDTH, \
			SCREEN_HEIGHT);
	my_mlx->main_img.addr = mlx_get_data_addr(my_mlx->main_img.img, \
			&my_mlx->main_img.bits_per_pixel, \
			&my_mlx->main_img.line_length, &my_mlx->main_img.endian);
	put_map(my_mlx);
	mlx_put_image_to_window(my_mlx->mlx, my_mlx->mlx_win, \
			my_mlx->main_img.img, 0, 0);
	*counter = 0;
	bonus_print(my_mlx, counter);
	return (0);
}
