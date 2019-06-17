/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 16:56:59 by abenani           #+#    #+#             */
/*   Updated: 2019/06/12 21:30:53 by abenani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int g_count = 0;

int		check_tetrimino_p2(char **holder, int i, int j, int v)
{
	if ((i - 1 > -1) && holder[i - 1][j] == '#')
		v++;
	if ((i + 1 < 4) && holder[i + 1][j] == '#')
		v++;
	if ((j - 1 > -1) && holder[i][j - 1] == '#')
		v++;
	if ((j + 1 < 4) && holder[i][j + 1] == '#')
		v++;
	return (v);
}

int		check_tetrimino(char **holder)
{
	t_var	var;

	var.i = -1;
	var.b = 0;
	var.d = 0;
	var.v = 0;
	while (++var.i < 4)
	{
		var.j = -1;
		while (++var.j < 4)
		{
			if (holder[var.i][var.j] == '.')
				var.d++;
			if (holder[var.i][var.j] == '#')
			{
				var.b++;
				var.v = check_tetrimino_p2(holder, var.i, var.j, var.v);
			}
		}
	}
	if (var.d != 12 || var.b != 4 || var.v < 6)
		return (0);
	return (1);
}

void	free_holder(char **s)
{
	int i;

	i = 0;
	while (i < 4)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

char	**my_tetrimino(int fd)
{
	t_var		var;

	var.holder = (char**)malloc(sizeof(char*) * 4);
	var.i = -1;
	while (++var.i < 4)
		var.holder[var.i] = (char*)malloc(sizeof(char) * 4);
	var.i = -1;
	while (++var.i < 4)
	{
		if (!get_next_line(fd, &var.line))
			break ;
		if (ft_strlen(var.line) != 5 || g_count > 130)
		{
			free(var.line);
			free_holder(var.holder);
			return (NULL);
		}
		g_count++;
		var.j = -1;
		while (++var.j < 4)
			var.holder[var.i][var.j] = var.line[var.j];
		free(var.line);
	}
	g_count++;
	return (var.holder);
}
