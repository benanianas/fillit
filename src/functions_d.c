/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenani <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 17:02:48 by abenani           #+#    #+#             */
/*   Updated: 2019/06/12 18:32:10 by abenani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	main_rest(char ***saver)
{
	char **square;

	replacing_tetriminos(saver);
	custom_tetri(saver);
	square = output(saver);
	printnfree_square(square);
	free_saver(saver);
}

void	free_saver(char ***saver)
{
	int i;

	i = 0;
	while (saver[i])
	{
		free_holder(saver[i]);
		i++;
	}
	free(saver);
}

void	free_square(char **s)
{
	int i;
	int size;

	size = 0;
	i = 0;
	while (s[size])
		size++;
	while (i < size)
	{
		free(s[i]);
		i++;
	}
	free(s);
}
