/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 20:44:44 by vismaily          #+#    #+#             */
/*   Updated: 2021/10/18 22:03:14 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	**map;
	size_t	map_height;

	if (argc == 2)
	{
		fd = file_open(argv[1]);
		if (fd > 0)
		{
			map_height = read_map_2d(fd, &map);
			if (map_height == (size_t)(-1))
			{
				printf("Map is empty :(\n");
				return (0);
			}
			if (map_parsing(&map, map_height) == 0)
				so_long(&map, map_height);
		}
		else
			printf("File open error\n");
	}
	else
		printf("You must give 1 argument to your program,"
			" and that have to be a map with .ber extension\n");
	return (0);
}
