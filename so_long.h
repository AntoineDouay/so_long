/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:42:01 by adouay            #+#    #+#             */
/*   Updated: 2022/08/28 19:14:11 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
#include "get_next_line_bonus.h"
# include "libft/libft.h"

/*
typedef	enum	s_carac{
	VOID = 48;
	WALL = 49;
	PLAYER = 80;
	COLLECTIBLE = 67;
	EXIT = 69;

}	t_carac
*/
typedef	struct	s_img{
	void	*img;
//	char	*path;
	int		width;
	int		height;
}	t_img;

typedef	struct	s_map{
	char	**map;
	int		line_len;
	int		line_nbr;
	int		player_i;
	int		player_j;
	int		exit_pos_i;
	int		exit_pos_j;
	int		open_exit;
	int		wall_render;
	int		file_exist;
}	t_map;

typedef	struct	s_data{
	void	*mlx_ptr;
	void	*win_ptr;
	int		step;
	t_img	isaac;
	t_img	background;
	t_img	wall;
	t_img	coin;
	t_img	trap;
	t_map	map;
}	t_data;

int	check_map(t_data *data, char **argv);
int check_coin(t_data *data);

int 	coe(t_data *data, char c);
void	get_player_pos(t_data *data);
int		check_coin(t_data *data);

void    player_move_up(t_data *data);
void    player_move_down(t_data *data);
void    player_move_left(t_data *data);
void    player_move_right(t_data *data);
void	render_wall(t_data *data);

#endif