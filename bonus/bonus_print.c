/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 17:45:53 by vismaily          #+#    #+#             */
/*   Updated: 2021/10/11 00:03:56 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	bonus_print(t_mlx *my_mlx, int *counter)
{
	char		*count;
	static int	first = 0;

	count = NULL;
	if (first == 0)
	{
		first++;
		mlx_string_put(my_mlx->mlx, my_mlx->mlx_win, 920, 43, 0x00FFFFFF, \
				"STEPS - 0");
	}
	else
	{
		count = ft_itoa(*counter);
		mlx_string_put(my_mlx->mlx, my_mlx->mlx_win, 920, 43, \
				0x00FFFFFF, "STEPS - ");
		mlx_string_put(my_mlx->mlx, my_mlx->mlx_win, 1000, 43, \
				0x00FFFFFF, count);
		free(count);
	}
}
