/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 20:54:34 by vismaily          #+#    #+#             */
/*   Updated: 2021/10/18 22:12:37 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define SCREEN_WIDTH 1900
# define SCREEN_HEIGHT 1000
# define STEPS 25

# include <stdio.h>
# include "libft.h"
# include "libgnl.h"
# include "mlx.h"
# include "keys.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_files {
	t_data	texture;
	int		height;
	int		width;
}				t_files;

typedef struct s_map {
	char	**map;
	char	**map_initial;
	size_t	map_height;
	size_t	map_width;
	char	value;
	int		color;
	size_t	p_i;
	size_t	p_j;
	size_t	i;
	size_t	j;
}				t_map;

typedef struct s_mlx {
	void	*mlx;
	void	*mlx_win;
	size_t	cub_width;
	size_t	cub_height;
	t_map	my_map;
	t_data	main_img;
	t_files	w;
	t_files	e;
	t_files	f;
	t_files	p;
	t_files	c;
	t_files	n;
}				t_mlx;

int		so_long(char ***map, size_t map_height);
int		map_parsing(char ***map, size_t map_height);
void	put_pixel(t_data *data, int x, int y, int color);
int		get_color(t_data *data, int x, int y);
void	get_my_color(t_map *t_my_map, t_mlx *my_mlx, int i, int j);
void	get_my_color_png(t_map *t_my_map, t_mlx *my_mlx, int i, int j);
void	set_textures(t_mlx *my_mlx);
int		ft_close(t_mlx *mlx);
int		ft_press(int key, t_mlx *mlx);
int		put_map(t_mlx *my_mlx);
int		wall_checker(int key, t_mlx *my_mlx, int *step);
void	put_p(t_mlx *my_mlx);
void	clean_p(t_mlx *my_mlx);
void	clean_c(int key, t_mlx *my_mlx, int step);
int		ft_close(t_mlx *my_mlx);
void	ft_exit(int *counter, t_mlx *my_mlx);
void	map_copy(t_mlx *my_mlx, char ***map, char ***map_2);
void	bonus_print(t_mlx *my_mlx, int *counter);
int		bonus_reset(t_mlx *my_mlx, int *counter);

#endif
