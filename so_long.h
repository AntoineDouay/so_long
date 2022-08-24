/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:42:01 by adouay            #+#    #+#             */
/*   Updated: 2022/08/24 19:13:08 by adouay           ###   ########.fr       */
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
}	t_map;

typedef	struct	s_data{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	isaac;
	t_img	background;
	t_img	wall;
	t_img	coin;
	t_map	map;
}	t_data;

int	check_map(t_data *data, char **argv);

#endif