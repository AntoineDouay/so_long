/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:34:10 by adouay            #+#    #+#             */
/*   Updated: 2022/08/29 05:58:34 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_var(t_data *data)
{
	data->map.open_exit = 0;
	data->step = 0;
	data->map.wall_render = 0;
	data->isaac_f.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"sprite/isaac_f.xpm", &data->isaac_f.width, &data->isaac_f.height);
	data->isaac_b.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"sprite/isaac_b.xpm", &data->isaac_b.width, &data->isaac_b.height);
	data->isaac_l.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"sprite/isaac_l.xpm", &data->isaac_l.width, &data->isaac_l.height);
	data->isaac_r.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"sprite/isaac_r.xpm", &data->isaac_r.width, &data->isaac_r.height);
	data->enemies.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"sprite/enemies.xpm", &data->enemies.width, &data->enemies.height);
	data->bg.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"sprite/background.xpm", &data->bg.width, &data->bg.height);
	data->wall.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"sprite/wall.xpm", &data->wall.width, &data->wall.height);
	data->coin.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"sprite/coin.xpm", &data->coin.width, &data->coin.height);
	data->trap.img = mlx_xpm_file_to_image(data->mlx_ptr,
			"sprite/trap.xpm", &data->trap.width, &data->trap.height);
	set_isaac_sprite(data);
	data->isaac_down = 1;
}

void	coe(t_data *data, char c)
{
	if (c == 'M')
	{
		printf("GAME OVER\n");
		no_leak_exit(data);
	}
	if (c == 'E' && data->map.open_exit == 1)
	{
		printf("gg\n");
		no_leak_exit(data);
	}
}

int	handle_key_input(int key, t_data *data)
{
	if (key == 65307)
		no_leak_exit(data);
	if (key == 119)
		player_move_up(data);
	if (key == 97)
		player_move_left(data);
	if (key == 115)
		player_move_down(data);
	if (key == 100)
		player_move_right(data);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (write(1, "Error\n", 6));
	if (check_map(&data, argv))
	{
		if (data.map.file_exist == 1)
			free_double_array(data.map.map);
		return (write(1, "Error\n", 6));
	}
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map.line_len * 50,
			(data.map.line_nbr + 1) * 50, "force");
	set_var(&data);
	render(&data);
	mlx_hook(data.win_ptr, 02, 1L << 0, &handle_key_input, &data);
	mlx_hook(data.win_ptr, 17, 0L, &no_leak_exit, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
