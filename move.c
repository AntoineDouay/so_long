/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:34:48 by adouay            #+#    #+#             */
/*   Updated: 2022/08/28 18:24:30 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_move_up(t_data *data)
{
	get_player_pos(data);
	if (data->map.map[data->map.player_i - 1][data->map.player_j] != '1')
	{
		coe(data, data->map.map[data->map.player_i - 1][data->map.player_j]);
		data->map.map[data->map.player_i - 1][data->map.player_j] = 'P';
		data->map.map[data->map.player_i][data->map.player_j] = '0';
	}
	if (!data->map.open_exit)
		if (check_coin(data))
		{
			data->map.open_exit = 1;
			data->map.map[data->map.exit_pos_i][data->map.exit_pos_j] = 'E';
		}
	render_wall(data);
	data->step++;
}

void	player_move_down(t_data *data)
{
	get_player_pos(data);
	if (data->map.map[data->map.player_i + 1][data->map.player_j] != '1')
	{
		coe(data, data->map.map[data->map.player_i + 1][data->map.player_j]);
		data->map.map[data->map.player_i + 1][data->map.player_j] = 'P';
		data->map.map[data->map.player_i][data->map.player_j] = '0';
	}
	if (!data->map.open_exit)
		if (check_coin(data))
		{
			data->map.open_exit = 1;
			data->map.map[data->map.exit_pos_i][data->map.exit_pos_j] = 'E';
		}
	render_wall(data);
	data->step++;
}

void	player_move_left(t_data *data)
{
	get_player_pos(data);
	if (data->map.map[data->map.player_i][data->map.player_j - 1] != '1')
	{
		coe(data, data->map.map[data->map.player_i][data->map.player_j - 1]);
		data->map.map[data->map.player_i][data->map.player_j - 1] = 'P';
		data->map.map[data->map.player_i][data->map.player_j] = '0';
	}
	if (!data->map.open_exit)
		if (check_coin(data))
		{
			data->map.open_exit = 1;
			data->map.map[data->map.exit_pos_i][data->map.exit_pos_j] = 'E';
		}
	render_wall(data);
	data->step++;
}

void	player_move_right(t_data *data)
{
	get_player_pos(data);
	if (data->map.map[data->map.player_i][data->map.player_j + 1] != '1')
	{
		coe(data, data->map.map[data->map.player_i][data->map.player_j + 1]);
		data->map.map[data->map.player_i][data->map.player_j + 1] = 'P';
		data->map.map[data->map.player_i][data->map.player_j] = '0';
	}
	if (!data->map.open_exit)
		if (check_coin(data))
		{
			data->map.open_exit = 1;
			data->map.map[data->map.exit_pos_i][data->map.exit_pos_j] = 'E';
		}
	render_wall(data);
	data->step++;
}
