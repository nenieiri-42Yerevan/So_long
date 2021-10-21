/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 20:40:57 by vismaily          #+#    #+#             */
/*   Updated: 2021/10/08 21:55:01 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgnl.h"

static void	ft_line_len(size_t *len_s1, size_t *len_s2, char **s1, char **s2)
{	
	if (*s1 == NULL)
		*len_s1 = 0;
	else
		*len_s1 = ft_strlen(*s1) + 1;
	if (*s2 == NULL)
		*len_s2 = 0;
	else
		*len_s2 = ft_strlen(*s2);
}

static char	*ft_realloc_join(char **s1, char **s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*new_str;

	ft_line_len(&len_s1, &len_s2, s1, s2);
	new_str = ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (new_str == NULL)
		return (0);
	new_str[len_s1 + len_s2] = '\0';
	if (*s1 != NULL)
	{
		ft_strlcpy(new_str, *s1, len_s1);
		new_str[len_s1 - 1] = '\n';
	}
	ft_strlcat(new_str, *s2, len_s1 + len_s2 + 1);
	return (new_str);
}

size_t	read_map_1d(int fd, char **map)
{
	char	*line;
	int		result;
	char	*tmp;

	(*map) = NULL;
	if (fd > 0)
	{
		result = get_next_line(fd, &line);
		while (result > 0)
		{
			tmp = ft_realloc_join(map, &line);
			if ((*map) != NULL)
				free(*map);
			*map = tmp;
			free(line);
			result = get_next_line(fd, &line);
		}
		free(line);
		if (result < 0)
			write(1, "Map read error\n", 15);
		close(fd);
		if (*map != NULL)
			return (ft_strlen(*map));
	}
	return (-1);
}
