/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:34:10 by adouay            #+#    #+#             */
/*   Updated: 2022/09/21 12:17:52 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_var_null(t_data *data)
{
	data->isaac_f.img = NULL;
	data->isaac_b.img = NULL;
	data->isaac_l.img = NULL;
	data->isaac_r.img = NULL;
	data->enemies.img = NULL;
	data->bg.img = NULL;
	data->wall.img = NULL;
	data->coin.img = NULL;
	data->trap.img = NULL;
}

void	set_var(t_data *data)
{
	data->map.open_exit = 0;
	data->step = 0;
	data->map.wall_render = 0;
	set_img_np(data, &data->isaac_f, "sprite/isaac_f.xpm");
	set_img_np(data, &data->isaac_b, "sprite/isaac_b.xpm");
	set_img_np(data, &data->isaac_l, "sprite/isaac_l.xpm");
	set_img_np(data, &data->isaac_r, "sprite/isaac_r.xpm");
	set_img_np(data, &data->enemies, "sprite/enemies.xpm");
	set_img_np(data, &data->bg, "sprite/background.xpm");
	set_img_np(data, &data->wall, "sprite/wall.xpm");
	set_img_np(data, &data->coin, "sprite/coin.xpm");
	set_img_np(data, &data->trap, "sprite/trap.xpm");
	set_isaac_sprite(data);
	data->isaac_down = 1;
}

void	coe(t_data *data, char c)
{
	if (c == 'M')
	{
		ft_printf("GAME OVER\n");
		no_leak_exit(data);
	}
	if (c == 'E' && data->map.open_exit == 1)
	{
		data->step++;
		ft_printf("well played, final score : %i\n", data->step);
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
		return (0);
	}
	check_valid_path(&data);
	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		no_leak_exit(&data);
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map.line_len * 50,
			(data.map.line_nbr + 1) * 50, "so_long");
	if (!data.win_ptr)
		no_leak_exit(&data);
	set_var_null(&data);
	set_var(&data);
	render(&data);
	mlx_hook(data.win_ptr, 02, 1L << 0, &handle_key_input, &data);
	mlx_hook(data.win_ptr, 17, 0L, &no_leak_exit, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
