/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 18:21:39 by vismaily          #+#    #+#             */
/*   Updated: 2021/10/18 20:29:19 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	map_errors(int err)
{
	if (err == 1)
		printf("The map must be rectangular.\n");
	else if (err == 2)
		printf("The map must be closed/surrounded by walls.\n");
	else if (err == 3)
		printf("The map must have at least 1 collectible.\n");
	else if (err == 4)
		printf("The map must have 1 player and 1 exit.\n");
	else if (err == 5)
		printf("The map does not exist.\n");
	else if (err == 6)
		printf("The map must consist only 'P' 'E' 'C' '1' '0' characters\n");
	else if (err == 7)
		printf("The map can't have 1 line or 1 column\n");
	return (-1);
}

static int	parsing_lines(char ***map, size_t line, size_t len, size_t height)
{
	size_t	j;
	int		res;

	res = 0;
	j = -1;
	if (line == 0 || line == (height - 1))
	{
		while (++j < len)
		{
			if ((*map)[line][j] != '1')
			{
				res = map_errors(2);
				return (res);
			}
		}
	}
	else if ((*map)[line][0] != '1' || (*map)[line][len - 1] != '1')
		res = map_errors(2);
	return (res);
}

static int	parsing_inner(char ***map, size_t len, size_t height)
{
	int		c;
	int		pe;
	size_t	i;
	size_t	j;

	c = 0;
	pe = 0;
	i = -1;
	while (++i < height)
	{
		j = -1;
		while (++j < len)
		{
			if ((*map)[i][j] == 'C')
				c++;
			else if (((*map)[i][j] == 'P') || ((*map)[i][j] == 'E'))
				pe++;
		}
	}
	if (c < 1)
		return (map_errors(3));
	else if (pe != 2)
		return (map_errors(4));
	else
		return (0);
}

static int	parsing_chars(char ***map, size_t i, size_t len)
{
	size_t	j;
	char	bonus[7];
	char	nobonus[6];

	j = -1;
	ft_strlcpy(bonus, "CPE10N", 7);
	ft_strlcpy(nobonus, "CPE10", 6);
	while (++j < len)
	{
		if (BONUS == 1)
		{
			if (ft_strchr(bonus, (*map)[i][j]) == NULL)
				return (map_errors(6));
		}
		else
			if (ft_strchr(nobonus, (*map)[i][j]) == NULL)
				return (map_errors(6));
	}
	return (0);
}

int	map_parsing(char ***map, size_t map_height)
{
	size_t	i;
	size_t	len;

	i = -1;
	len = ft_strlen((*map)[0]);
	while (++i < map_height)
	{
		if (len == ft_strlen((*map)[i]))
			len = ft_strlen((*map)[i]);
		else
			return (map_errors(1));
		if (parsing_lines(map, i, len, map_height) == -1)
			return (-1);
		if (parsing_chars(map, i, len) == -1)
			return (-1);
	}
	if (len == 0 && map_height == 1)
		return (map_errors(5));
	else if (len == 1 || map_height == 1)
		return (map_errors(7));
	return (parsing_inner(map, len, map_height));
}
