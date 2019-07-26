/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 01:15:34 by abenani           #+#    #+#             */
/*   Updated: 2019/07/26 13:06:33 by abenani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**smallest_square(char ***saver)
{
	t_bvar		var;
	static int	add = 0;

	var.i = 0;
	var.size = smallest_possible_square(saver);
	var.size += add;
	add++;
	var.square = (char**)malloc(sizeof(char*) * (var.size + 2));
	while (var.i < (var.size + 1))
	{
		var.square[var.i] = (char*)malloc(sizeof(char) * (var.size + 1));
		var.j = 0;
		while (var.j < var.size)
		{
			if (var.i == var.size)
				var.square[var.i][var.j] = '\0';
			else
				var.square[var.i][var.j] = '.';
			var.j++;
		}
		var.square[var.i][var.j] = '\0';
		var.i++;
	}
	var.square[var.i] = NULL;
	return (var.square);
}

int		is_it_safe(char **square, char **tetr, int i, int j)
{
	int a;
	int b;
	int count;

	count = 0;
	a = 0;
	while (a < 4)
	{
		b = 0;
		while (b < 4)
		{
			if (ft_isalpha(tetr[a][b]) && square[a + i][b + j] == '\0')
				return (0);
			if (ft_isalpha(tetr[a][b]) && square[a + i][b + j] == '.')
				count++;
			if (count == 4)
			{
				place_it(square, tetr, i, j);
				return (1);
			}
			b++;
		}
		a++;
	}
	return (0);
}

void	place_it(char **square, char **tetr, int i, int j)
{
	int a;
	int b;
	int count;

	count = 0;
	a = 0;
	while (a < 4)
	{
		b = 0;
		while (b < 4)
		{
			if (tetr[a][b] != '.')
			{
				square[a + i][b + j] = tetr[a][b];
				count++;
			}
			if (count == 4)
				return ;
			b++;
		}
		a++;
	}
}

void	remove_it(char **square, char **tetr, int i, int j)
{
	int a;
	int b;
	int count;

	count = 0;
	a = 0;
	while (a < 4)
	{
		b = 0;
		while (b < 4)
		{
			if (tetr[a][b] != '.')
			{
				square[a + i][b + j] = '.';
				count++;
			}
			if (count == 4)
				return ;
			b++;
		}
		a++;
	}
}

int		output_square(char **square, char ***saver, int num)
{
	int i;
	int j;

	if (!saver[num])
		return (1);
	i = 0;
	while (square[i + 1])
	{
		j = 0;
		while (square[i][j])
		{
			if (is_it_safe(square, saver[num], i, j))
			{
				if (output_square(square, saver, num + 1))
					return (1);
				else
					remove_it(square, saver[num], i, j);
			}
			j++;
		}
		i++;
	}
	return (0);
}
