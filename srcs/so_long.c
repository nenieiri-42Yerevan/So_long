/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 20:44:13 by vismaily          #+#    #+#             */
/*   Updated: 2021/10/18 22:06:28 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_copy(t_mlx *my_mlx, char ***map, char ***map_2)
{
	size_t	i;

	i = -1;
	(*map_2) = ft_calloc(my_mlx->my_map.map_height, sizeof(char *));
	while (++i < my_mlx->my_map.map_height)
	{
		(*map_2)[i] = ft_calloc(my_mlx->my_map.map_width + 1, sizeof(char));
		ft_strlcpy ((*map_2)[i], (*map)[i], \
				my_mlx->my_map.map_width + 1);
		(*map_2)[i][my_mlx->my_map.map_width] = '\0';
	}
}

void	my_mlx_init(t_mlx *my_mlx, char ***map, size_t map_height)
{
	char	**map_2;

	my_mlx->my_map.map = *map;
	my_mlx->my_map.map_height = map_height;
	my_mlx->my_map.map_width = ft_strlen(my_mlx->my_map.map[0]);
	my_mlx->cub_height = SCREEN_HEIGHT / my_mlx->my_map.map_height;
	my_mlx->cub_width = SCREEN_WIDTH / my_mlx->my_map.map_width;
	my_mlx->mlx_win = mlx_new_window(my_mlx->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, \
			"so_long");
	my_mlx->main_img.img = mlx_new_image(my_mlx->mlx, SCREEN_WIDTH, \
			SCREEN_HEIGHT);
	my_mlx->main_img.addr = mlx_get_data_addr(my_mlx->main_img.img, \
			&my_mlx->main_img.bits_per_pixel, \
			&my_mlx->main_img.line_length, &my_mlx->main_img.endian);
	set_textures(my_mlx);
	map_copy(my_mlx, &(my_mlx->my_map.map), &map_2);
	my_mlx->my_map.map_initial = map_2;
}

int	so_long(char ***map, size_t map_height)
{
	t_mlx	my_mlx;

	my_mlx.mlx = mlx_init();
	if (my_mlx.mlx == NULL)
		printf("MiniLibX connection error\n");
	else
	{
		my_mlx_init(&my_mlx, map, map_height);
		put_map(&my_mlx);
		mlx_put_image_to_window(my_mlx.mlx, my_mlx.mlx_win, \
			my_mlx.main_img.img, 0, 0);
		if (BONUS == 1)
			bonus_print(&my_mlx, 0);
		mlx_hook(my_mlx.mlx_win, 17, 1L << 17, ft_close, &my_mlx);
		mlx_hook(my_mlx.mlx_win, 2, 1L << 2, ft_press, &my_mlx);
		mlx_loop(my_mlx.mlx);
	}
	return (0);
}
