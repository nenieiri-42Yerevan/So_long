/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 16:15:47 by vismaily          #+#    #+#             */
/*   Updated: 2021/10/18 23:51:31 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_symbol_1(char s1, char s2)
{
	if ((s1 == 'P' && s2 == '0') || (s1 == '0' && s2 == 'P'))
		return (1);
	else if (s1 == 'P' && s2 == 'P')
		return (1);
	else if (s1 == '0' && s2 == '0')
		return (1);
	else if (((s1 == 'N' && s2 == '0') || (s1 == '0' && s2 == 'N')) && \
			BONUS == 1)
		return (4);
	else if (((s1 == 'N' && s2 == 'C') || (s1 == 'C' && s2 == 'N')) && \
			BONUS == 1)
		return (4);
	else if ((s1 == 'N' && s2 == 'N') && BONUS == 1)
		return (4);
	else if ((s1 == 'E' && s2 == 'P') || (s2 == 'E' && s1 == 'P'))
		return (3);
	else
		return (0);
}

static int	ft_symbol(char s1, char s2)
{
	if (s1 == '1' && (s2 == '0' || s2 == 'P' || s2 == 'C' || s2 == 'E' || \
				s2 == 'N'))
		return (0);
	else if (s2 == '1' && (s1 == '0' || s1 == 'P' || s1 == 'C' || s1 == 'E' || \
				s1 == 'N'))
		return (0);
	else if ((s1 == 'E' && s2 == 'C') || (s2 == 'E' && s1 == 'C'))
		return (0);
	else if ((s1 == 'E' && s2 == '0') || (s2 == 'E' && s1 == '0'))
		return (3);
	else if (s1 == 'E' && s2 == 'E')
		return (3);
	else if ((s1 == 'C' && s2 == '0') || (s2 == 'C' && s1 == '0'))
		return (2);
	else if (s1 == 'C' && s2 == 'C')
		return (2);
	else if ((s1 == 'C' && s2 == 'P') || (s1 == 'P' && s2 == 'C'))
		return (2);
	else
		return (ft_symbol_1(s1, s2));
}

static int	ft_up_down(int key, t_mlx *my_mlx, int *step)
{
	int		i;
	int		j;
	int		kj;

	i = my_mlx->cub_height;
	j = my_mlx->cub_width;
	if (key == KEY_W)
		i = (my_mlx->my_map.p_i - *step) / i;
	else
		i = (my_mlx->my_map.p_i + *step + i - 1) / i;
	kj = (my_mlx->my_map.p_j + j - 1) / j;
	j = my_mlx->my_map.p_j / j;
	return (ft_symbol(my_mlx->my_map.map[i][j], my_mlx->my_map.map[i][kj]));
}

static int	ft_left_right(int key, t_mlx *my_mlx, int *step)
{
	int		i;
	int		j;
	int		ki;

	i = my_mlx->cub_height;
	j = my_mlx->cub_width;
	if (key == KEY_A)
		j = (my_mlx->my_map.p_j - *step) / j;
	else
		j = (my_mlx->my_map.p_j + *step + j - 1) / j;
	ki = (my_mlx->my_map.p_i + i - 1) / i;
	i = my_mlx->my_map.p_i / i;
	return (ft_symbol(my_mlx->my_map.map[i][j], my_mlx->my_map.map[ki][j]));
}

int	wall_checker(int key, t_mlx *my_mlx, int *step)
{
	if (key == KEY_W || key == KEY_S)
		return (ft_up_down(key, my_mlx, step));
	else
		return (ft_left_right(key, my_mlx, step));
}
