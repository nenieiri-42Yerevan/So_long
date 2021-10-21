/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:02:12 by vismaily          #+#    #+#             */
/*   Updated: 2021/10/18 19:16:05 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#define W "./images/wall.xpm" 
#define E "./images/exit.xpm" 
#define F "./images/greece.xpm" 
#define P "./images/persone.xpm" 
#define C "./images/flower1.xpm" 
#define N "./images/toxic.xpm" 

static void	set_textures_bonus(t_mlx *my_mlx)
{
	t_files	n;

	n.texture.img = mlx_xpm_file_to_image(my_mlx->mlx, N, &(n.width), \
			&(n.height));
	n.texture.addr = mlx_get_data_addr(n.texture.img, \
			&(n.texture.bits_per_pixel), &(n.texture.line_length), \
			&(n.texture.endian));
	my_mlx->n = n;
}

static void	set_textures_1(t_mlx *my_mlx)
{	
	t_files	p;
	t_files	c;
	t_files	e;

	e.texture.img = mlx_xpm_file_to_image(my_mlx->mlx, E, &(e.width), \
			&(e.height));
	e.texture.addr = mlx_get_data_addr(e.texture.img, \
			&(e.texture.bits_per_pixel), &(e.texture.line_length), \
			&(e.texture.endian));
	p.texture.img = mlx_xpm_file_to_image(my_mlx->mlx, P, &(p.width), \
			&(p.height));
	p.texture.addr = mlx_get_data_addr(p.texture.img, \
			&(p.texture.bits_per_pixel), &(p.texture.line_length), \
			&(p.texture.endian));
	c.texture.img = mlx_xpm_file_to_image(my_mlx->mlx, C, &(c.width), \
			&(c.height));
	c.texture.addr = mlx_get_data_addr(c.texture.img, \
			&(c.texture.bits_per_pixel), &(c.texture.line_length), \
			&(c.texture.endian));
	my_mlx->p = p;
	my_mlx->c = c;
	my_mlx->e = e;
}

void	set_textures(t_mlx *my_mlx)
{
	t_files	w;
	t_files	f;

	w.texture.img = mlx_xpm_file_to_image(my_mlx->mlx, W, &(w.width), \
			&(w.height));
	w.texture.addr = mlx_get_data_addr(w.texture.img, \
			&(w.texture.bits_per_pixel), &(w.texture.line_length), \
			&(w.texture.endian));
	f.texture.img = mlx_xpm_file_to_image(my_mlx->mlx, F, &(f.width), \
			&(f.height));
	f.texture.addr = mlx_get_data_addr(f.texture.img, \
			&(f.texture.bits_per_pixel), &(f.texture.line_length), \
			&(f.texture.endian));
	my_mlx->w = w;
	my_mlx->f = f;
	set_textures_1(my_mlx);
	if (BONUS == 1)
		set_textures_bonus(my_mlx);
}
