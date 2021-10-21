/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 19:56:54 by vismaily          #+#    #+#             */
/*   Updated: 2021/10/18 23:45:31 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_p(t_mlx *my_mlx)
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
			get_my_color_png(&(my_mlx->my_map), my_mlx, j, i);
			if ((my_mlx->my_map.color & 0xFF000000) == 0xFF000000)
				continue ;
			put_pixel(&(my_mlx->main_img), my_mlx->my_map.j + j, \
				my_mlx->my_map.i + i, my_mlx->my_map.color);
		}
	}
}

void	move_p(int key, t_mlx *my_mlx, int *step, int *counter)
{
	if (key == KEY_W)
		my_mlx->my_map.p_i -= *step;
	else if (key == KEY_S)
		my_mlx->my_map.p_i += *step;
	else if (key == KEY_A)
		my_mlx->my_map.p_j -= *step;
	else if (key == KEY_D)
		my_mlx->my_map.p_j += *step;
	my_mlx->my_map.value = 'P';
	my_mlx->my_map.i = my_mlx->my_map.p_i;
	my_mlx->my_map.j = my_mlx->my_map.p_j;
	put_p(my_mlx);
	mlx_put_image_to_window(my_mlx->mlx, my_mlx->mlx_win, \
			my_mlx->main_img.img, 0, 0);
	(*counter)++;
	if (BONUS == 1)
		bonus_print(my_mlx, counter);
	else
		printf("%d\n", *counter);
}

int	finish(t_mlx *my_mlx)
{
	size_t	i;
	size_t	j;

	i = -1;
	while (++i < my_mlx->my_map.map_height)
	{
		j = -1;
		while (++j < my_mlx->my_map.map_width)
		{
			if (my_mlx->my_map.map[i][j] == 'C')
				return (0);
		}
	}
	return (1);
}

int	ft_press(int key, t_mlx *my_mlx)
{
	int			step;
	int			checker;
	static int	counter = 0;

	step = STEPS;
	if (key == KEY_ESC)
		ft_close(my_mlx);
	else if (key == KEY_W || key == KEY_S || key == KEY_A || key == KEY_D)
	{
		checker = wall_checker(key, my_mlx, &step);
		if (checker == 1 || checker == 2)
		{
			clean_p(my_mlx);
			move_p(key, my_mlx, &step, &counter);
			if (checker == 2)
				clean_c(key, my_mlx, step);
		}
		if (checker == 3 && finish(my_mlx) == 1)
			ft_exit(&counter, my_mlx);
		else if (checker == 4 && BONUS == 1)
			bonus_reset(my_mlx, &counter);
	}
	return (0);
}
