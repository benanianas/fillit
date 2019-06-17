/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbhaya <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:15:21 by mbhaya            #+#    #+#             */
/*   Updated: 2019/06/12 18:32:16 by abenani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "../GNL/get_next_line.h"
# include <stdio.h>

typedef struct	s_vars
{
	int		i;
	int		j;
	int		d;
	int		b;
	int		v;
	char	**holder;
	char	*line;
}				t_var;
typedef struct	s_bvars
{
	int		i;
	int		j;
	int		k;
	int		a;
	int		b;
	int		size;
	char	**square;
}				t_bvar;
int				check_tetrimino_p2(char **holder, int i, int j, int v);
int				check_tetrimino(char **holder);
void			free_holder(char **s);
char			**my_tetrimino(int fd);
void			saving_tetriminos(char **holder, char ***saver);
void			custom_tetri(char ***saver);
void			replacing_tetriminos(char ***saver);
void			continue_replacing(char **holder, int a, int b);
int				smallest_possible_square(char ***saver);
char			**smallest_square(char ***saver);
int				is_it_safe(char **square, char **tetr, int i, int j);
void			place_it(char **square, char **tetr, int i, int j);
void			remove_it(char **square, char **tetr, int i, int j);
int				output_square(char **square, char ***saver, int num);
char			**output(char ***saver);
void			free_square(char **s);
void			printnfree_square(char **square);
void			free_saver(char ***saver);
void			main_rest(char ***saver);
#endif
