/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/29 12:23:08 by abenani           #+#    #+#             */
/*   Updated: 2019/06/12 21:32:13 by abenani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_line(char *s, char **line)
{
	int		i;
	char	*rest;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	if (s[i] == '\n')
	{
		*line = ft_strsub(s, 0, i + 1);
		rest = ft_strdup(&s[i + 1]);
	}
	if (!s[i])
	{
		*line = ft_strsub(s, 0, i);
		rest = ft_strnew(0);
	}
	return (rest);
}

static t_node	*ft_head(t_node *node, int fd)
{
	if (!node)
	{
		node = (t_node*)malloc(sizeof(t_node));
		node->fd = fd;
		node->s = ft_strnew(0);
		node->head = node;
		node->next = NULL;
	}
	else
		node = node->head;
	return (node);
}

static t_node	*ft_getfd(t_node *node, int fd)
{
	while (node->next)
	{
		if (node->fd == fd)
			return (node);
		node = node->next;
	}
	if (node->fd == fd)
		return (node);
	node->next = malloc(sizeof(t_node));
	node->next->fd = fd;
	node->next->s = ft_strnew(0);
	node->next->head = node->head;
	node->next->next = NULL;
	return (node->next);
}

int				my_free(t_node *node)
{
	free(node->s);
	free(node);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_node	*node;
	char			buff[BUFF_SIZE + 1];
	int				rd;
	char			*tmp;

	node = ft_head(node, fd);
	node = ft_getfd(node, fd);
	if ((read(fd, buff, 0)) < 0 || fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	node->s = (!node->s) ? ft_strnew(0) : node->s;
	while ((rd = read(fd, buff, BUFF_SIZE)))
	{
		buff[rd] = '\0';
		tmp = ft_strjoin(node->s, buff);
		free(node->s);
		node->s = tmp;
		if (ft_strchr(node->s, '\n'))
			break ;
	}
	if (!rd && !ft_strlen(node->s))
		return (my_free(node));
	tmp = ft_line(node->s, line);
	free(node->s);
	node->s = tmp;
	return (1);
}
