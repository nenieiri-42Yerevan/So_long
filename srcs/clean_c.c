/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 20:52:47 by vismaily          #+#    #+#             */
/*   Updated: 2021/10/06 23:24:03 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	cleaner_c(t_mlx *my_mlx, size_t m_i, size_t m_j)
{
	if (my_mlx->my_map.map[m_i][m_j] == 'C')
	{
		my_mlx->my_map.map[m_i][m_j] = '0';
		my_mlx->my_map.value = '0';
		my_mlx->my_map.i = m_i * my_mlx->cub_height;
		my_mlx->my_map.j = m_j * my_mlx->cub_width;
		put_p(my_mlx);
		my_mlx->my_map.value = 'P';
		my_mlx->my_map.i = my_mlx->my_map.p_i;
		my_mlx->my_map.j = my_mlx->my_map.p_j;
		put_p(my_mlx);
	}
}

static size_t	long_step(size_t m, int step, int key)
{
	if ((step >= 100) && (key == KEY_S || key == KEY_D))
		return (m - 1);
	return (m);
}

static void	clean_c_1(int key, t_mlx *my_mlx, size_t m_i, size_t m_j)
{
	if (key == KEY_W)
	{
		cleaner_c(my_mlx, m_i, m_j);
		if (my_mlx->my_map.p_j != m_j * my_mlx->cub_width)
			cleaner_c(my_mlx, m_i, m_j + 1);
	}
	if (key == KEY_A)
	{
		cleaner_c(my_mlx, m_i, m_j);
		if (my_mlx->my_map.p_i != m_i * my_mlx->cub_height)
			cleaner_c(my_mlx, m_i + 1, m_j);
	}
}

void	clean_c(int key, t_mlx *my_mlx, int step)
{
	size_t	m_i;
	size_t	m_j;

	m_i = ((my_mlx->my_map.p_i / my_mlx->cub_height) * my_mlx->cub_height) / \
		  my_mlx->cub_height;
	m_j = ((my_mlx->my_map.p_j / my_mlx->cub_width) * my_mlx->cub_width) / \
		  my_mlx->cub_width;
	if (key == KEY_S)
	{	
		cleaner_c(my_mlx, long_step(m_i, step, key) + 1, m_j);
		if (my_mlx->my_map.p_j != m_j * my_mlx->cub_width)
			cleaner_c(my_mlx, long_step(m_i, step, key) + 1, m_j + 1);
	}
	else if (key == KEY_D)
	{
		cleaner_c(my_mlx, m_i, long_step(m_j, step, key) + 1);
		if (my_mlx->my_map.p_i != m_i * my_mlx->cub_height)
			cleaner_c(my_mlx, m_i + 1, long_step(m_j, step, key) + 1);
	}
	else
		clean_c_1(key, my_mlx, m_i, m_j);
}
