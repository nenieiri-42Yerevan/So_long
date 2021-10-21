/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 00:44:08 by vismaily          #+#    #+#             */
/*   Updated: 2021/09/21 00:44:27 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGNL_H
# define LIBGNL_H

# include <fcntl.h>
# include "libft.h"

int		get_next_line(int fd, char **line);
int		file_open(char *path);
size_t	read_map_1d(int fd, char **map);
size_t	read_map_2d(int fd, char ***map);

#endif
