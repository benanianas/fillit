/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 10:57:04 by abenani           #+#    #+#             */
/*   Updated: 2019/07/26 13:01:31 by abenani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int		is_it_valid(int fd, char ***saver)
{
	char	**holder;
	char	*line;

	holder = my_tetrimino(fd);
	saving_tetriminos(holder, saver);
	if ((!holder) || !(check_tetrimino(holder)))
		return (0);
	if (get_next_line(fd, &line) != 0)
	{
		if (line[0] == '\n')
		{
			free(line);
			return (is_it_valid(fd, saver));
		}
		else
		{
			free(line);
			return (0);
		}
	}
	return (1);
}

void	printnfree_square(char **square)
{
	int i;
	int j;

	i = 0;
	while (square[i + 1])
	{
		j = 0;
		while (square[i][j])
		{
			ft_putchar(square[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	free_square(square);
}

char	**output(char ***saver)
{
	char **square;

	square = smallest_square(saver);
	while (!output_square(square, saver, 0))
	{
		free_square(square);
		square = smallest_square(saver);
	}
	return (square);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	***saver;

	if (argc != 2)
		ft_putstr("usage:\t./fillit file (text file containing Tetriminos).\n");
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
		{
			ft_putendl("error");
			return (0);
		}
		saver = malloc(sizeof(char**) * 27);
		if (!is_it_valid(fd, saver))
		{
			ft_putendl("error");
			free_saver(saver);
		}
		else
			main_rest(saver);
	}
	return (0);
}
