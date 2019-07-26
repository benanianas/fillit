/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 04:31:14 by abenani           #+#    #+#             */
/*   Updated: 2019/07/26 13:05:11 by abenani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	saving_tetriminos(char **holder, char ***saver)
{
	static int	i = 0;

	saver[i] = holder;
	saver[i + 1] = NULL;
	i++;
}

void	custom_tetri(char ***saver)
{
	static char	letter = 'A';
	int			k;
	int			i;
	int			j;

	k = 0;
	while (saver[k])
	{
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				if (saver[k][i][j] == '#')
					saver[k][i][j] = letter;
				j++;
			}
			i++;
		}
		k++;
		letter++;
	}
}

void	replacing_tetriminos(char ***saver)
{
	t_bvar	var;

	var.k = -1;
	while (saver[++var.k])
	{
		var.i = -1;
		var.a = 13;
		var.b = 37;
		while (++var.i < 4)
		{
			var.j = -1;
			while (++var.j < 4)
			{
				if (saver[var.k][var.i][var.j] == '#')
				{
					if (var.i < var.a)
						var.a = var.i;
					if (var.j < var.b)
						var.b = var.j;
				}
			}
		}
		continue_replacing(saver[var.k], var.a, var.b);
	}
}

void	continue_replacing(char **holder, int a, int b)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (holder[i][j] == '#')
			{
				if (a || b)
				{
					holder[i - a][j - b] = '#';
					holder[i][j] = '.';
				}
			}
			j++;
		}
		i++;
	}
}

int		smallest_possible_square(char ***saver)
{
	int		i;
	int		num;

	i = 0;
	while (saver[i])
		i++;
	if (i == 1)
		return (2);
	num = i * 4;
	i = 1;
	while (i < num / 2)
	{
		if ((i * i) >= num)
			return (i);
		i++;
	}
	return (0);
}
