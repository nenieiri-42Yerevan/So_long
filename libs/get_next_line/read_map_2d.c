/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:05:03 by vismaily          #+#    #+#             */
/*   Updated: 2021/10/08 21:48:57 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgnl.h"

static size_t	map_height(const char *map_1d)
{
	size_t	i;
	size_t	height;

	i = 0;
	height = 0;
	while (map_1d[i] != '\0')
	{
		if (map_1d[i] == '\n')
			height++;
		i++;
	}
	return (height + 1);
}

static char	*map_element(char *map_1d, char **map_2d)
{
	int	i;

	i = 0;
	while (map_1d[i] != '\n' && map_1d[i] != '\0')
		i++;
	i++;
	(*map_2d) = ft_calloc(i, sizeof(char));
	if (map_2d == NULL)
		return (0);
	ft_strlcpy((*map_2d), map_1d, i);
	(*map_2d)[i - 1] = '\0';
	if (map_1d[i - 1] == '\n')
		map_1d = map_1d + i;
	else
		map_1d = map_1d + (i - 1);
	return (map_1d);
}

size_t	read_map_2d(int fd, char ***map)
{
	char	*map_1d;
	char	*map_1d_free;
	size_t	i;
	size_t	height;

	i = 0;
	read_map_1d(fd, &map_1d);
	if (map_1d == NULL)
		return (-1);
	map_1d_free = map_1d;
	height = map_height(map_1d);
	(*map) = ft_calloc(height, sizeof(char *));
	if (!(*map))
		return (0);
	while (i < height)
	{
		map_1d = map_element(map_1d, &((*map)[i]));
		i++;
	}
	if (map_1d_free != NULL)
		free(map_1d_free);
	return (height);
}
