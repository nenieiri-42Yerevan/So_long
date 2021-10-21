/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_close.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:40:38 by vismaily          #+#    #+#             */
/*   Updated: 2021/10/18 19:29:00 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close(t_mlx *my_mlx)
{
	mlx_destroy_image(my_mlx->mlx, my_mlx->w.texture.img);
	mlx_destroy_image(my_mlx->mlx, my_mlx->e.texture.img);
	mlx_destroy_image(my_mlx->mlx, my_mlx->f.texture.img);
	mlx_destroy_image(my_mlx->mlx, my_mlx->p.texture.img);
	mlx_destroy_image(my_mlx->mlx, my_mlx->c.texture.img);
	mlx_destroy_image(my_mlx->mlx, my_mlx->main_img.img);
	mlx_destroy_window(my_mlx->mlx, my_mlx->mlx_win);
	exit(0);
	return (0);
}

void	ft_exit(int *counter, t_mlx *my_mlx)
{
	(*counter)++;
	if (BONUS == 1)
		bonus_print(my_mlx, counter);
	else
		printf("%d\n", *counter);
	ft_close(my_mlx);
}
