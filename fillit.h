/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbashiri <bbashiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 14:35:45 by bbashiri          #+#    #+#             */
/*   Updated: 2018/12/20 03:18:16 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"

typedef struct	s_fil
{
	int			x[4];
	int			y[4];
	char		id;
}				t_fil;

int				check_start(int fd, t_fil *str);

char			**create_map(int map_size);
char			**init_map(int map_size);
void			delete_map(char **map, int map_size);

void			print_map(char **map, int map_size);
void			print_pieces(t_fil *tetras, int tetras_size);
void			print_piece(t_fil *tetrimino);

int				place_tetrimino(t_fil *tetriminos,
							int i,
							int tetras_size,
							char **map,
							int map_size);

#endif
