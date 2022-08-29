/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:42:01 by adouay            #+#    #+#             */
/*   Updated: 2022/08/29 06:42:10 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
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
	int		isaac_up;
	int		isaac_down;
	int		isaac_left;
	int		isaac_right;
	t_img	isaac_f;
	t_img	isaac_b;
	t_img	isaac_l;
	t_img	isaac_r;
	t_img	enemies;
	t_img	bg;
	t_img	wall;
	t_img	coin;
	t_img	trap;
	t_map	map;
}	t_data;

int	check_map(t_data *data, char **argv);
int check_coin(t_data *data);

void 	coe(t_data *data, char c);
void	get_player_pos(t_data *data);

int		check_coin(t_data *data);
/* -----map2.c----- */
void    get_player_pos(t_data *data);
int 	map_ber(char *file);
int 	valid_carac_map(t_data *data, char **map);
int 	valid(int p, int c, int e);
int 	check_carac(char **map);

/* -----render.c----- */

void    render_wall(t_data *data, char c, int i, int j);
void    render_step(t_data *data);
void    render_isaac(t_data *data, char c, int i, int j);
void    render_map(t_data *data, char c, int i, int j);
int		render(t_data *data);

/* -----move.c----- */

void    set_isaac_sprite(t_data *data);
void    player_move_up(t_data *data);
void    player_move_down(t_data *data);
void    player_move_left(t_data *data);
void    player_move_right(t_data *data);

/* -----free.c----- */
void	free_double_array(char **tab);
int	no_leak_exit(t_data *data);

#endif