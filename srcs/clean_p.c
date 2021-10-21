/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 23:23:05 by vismaily          #+#    #+#             */
/*   Updated: 2021/10/18 23:47:26 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clean(t_mlx *my_mlx, int i, int j)
{
	if (my_mlx->my_map.i != ((my_mlx->my_map.p_i + i - 1) / i) * i)
	{
		my_mlx->my_map.i = ((my_mlx->my_map.p_i + i - 1) / i) * i;
		put_p(my_mlx);
		my_mlx->my_map.i = (my_mlx->my_map.p_i / i) * i;
	}
	if (my_mlx->my_map.j != ((my_mlx->my_map.p_j + j - 1) / j) * j)
	{
		my_mlx->my_map.j = ((my_mlx->my_map.p_j + j - 1) / j) * j;
		put_p(my_mlx);
		my_mlx->my_map.j = (my_mlx->my_map.p_j / j) * j;
	}
	if ((my_mlx->my_map.i != ((my_mlx->my_map.p_i + i - 1) / i) * i) && \
			(my_mlx->my_map.j != ((my_mlx->my_map.p_j + j - 1) / j) * j))
	{
		my_mlx->my_map.j = ((my_mlx->my_map.p_j + j - 1) / j) * j;
		my_mlx->my_map.i = ((my_mlx->my_map.p_i + i - 1) / i) * i;
		put_p(my_mlx);
	}
}

void	clean_p(t_mlx *my_mlx)
{
	int	i;
	int	j;

	i = my_mlx->cub_height;
	j = my_mlx->cub_width;
	my_mlx->my_map.value = '0';
	my_mlx->my_map.i = (my_mlx->my_map.p_i / i) * i;
	my_mlx->my_map.j = (my_mlx->my_map.p_j / j) * j;
	put_p(my_mlx);
	clean(my_mlx, i, j);
}
