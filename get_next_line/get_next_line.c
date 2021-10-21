/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vismaily <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 21:04:01 by vismaily          #+#    #+#             */
/*   Updated: 2021/10/08 21:20:59 by vismaily         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libgnl.h"
#define BUFFER_SIZE 20

void	add_list(t_list **lst, char *content)
{
	t_list	*temp;
	char	*prev_content;

	if (*lst == NULL)
	{
		*lst = ft_lstnew(content);
		return ;
	}
	temp = (*lst);
	while ((*lst)->next)
		*lst = (*lst)->next;
	if (ft_strchr((*lst)->content, '\n'))
		(*lst)->next = ft_lstnew(content);
	else
	{
		prev_content = (*lst)->content;
		(*lst)->content = ft_strjoin(prev_content, content);
		free(content);
		free(prev_content);
	}
	*lst = temp;
}

int	parse_buffer(t_list **list, char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i++] == '\n' || buffer[i] == 0)
		{
			add_list(list, ft_strndup(buffer, i));
			buffer += i;
			i = 0;
		}
	}
	buffer -= 1;
	if (*buffer == '\n')
		add_list(list, ft_strndup("", 0));
	return (1);
}

void	write_line(t_list *list, char **line, int result)
{
	int		i;
	char	*c;

	if (list)
	{
		i = 0;
		c = ft_strchr(list->content, '\n');
		if (c != 0)
			i = (c - list->content) / sizeof(char);
		*line = ft_strndup(list->content, i);
	}
	else if (!result && BUFFER_SIZE != 0)
		*line = ft_strndup("", 0);
}

int	ft_result(t_list **element, int result, char *buffer)
{
	t_list	*temp;

	if (*element)
	{
		temp = (*element);
		(*element) = (*element)->next;
		free(temp->content);
		free(temp);
	}
	if (result <= 0)
		free(buffer);
	if (result == -1)
		return (-1);
	else if (result == 0 && *element == NULL)
		return (0);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int				result;
	char			*buffer;
	static t_list	*lists[14000];

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (line == NULL || fd < 0 || fd > 14000 || buffer == NULL)
		return (-1);
	buffer[BUFFER_SIZE] = '\0';
	result = read(fd, buffer, BUFFER_SIZE);
	while (result > 0)
	{
		if (ft_strchr(buffer, '\n'))
		{
			parse_buffer(&lists[fd], buffer);
			free(buffer);
			break ;
		}
		add_list(&lists[fd], buffer);
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		buffer[BUFFER_SIZE] = '\0';
		result = read(fd, buffer, BUFFER_SIZE);
	}
	write_line(lists[fd], line, result);
	return (ft_result(&lists[fd], result, buffer));
}
