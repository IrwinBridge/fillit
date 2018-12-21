/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:35:45 by bbashiri          #+#    #+#             */
/*   Updated: 2018/12/21 17:43:25 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

typedef struct	s_fil
{
	int			x[4];
	int			y[4];
	int			width;
	int			height;
	char		id;
}				t_fil;

typedef struct	s_prefs
{
	int			map_size;
	int			tetras_size;
}				t_prefs;

int				check_start(int fd, t_fil *str);
void			fill_width_height(t_fil *list);

char			**create_map(int map_size);
char			**init_map(int map_size);
int				is_map_blank(char **map, int map_size);
void			delete_map(char **map, int map_size);

void			print_map(char **map, int map_size);
int				place_tetrimino(t_fil *tetriminos,
								int i,
								char **map,
								t_prefs prefs);
#endif
