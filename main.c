/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:34:10 by adouay            #+#    #+#             */
/*   Updated: 2022/08/25 16:10:47 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_double_array(char **tab)
{
	int	i;

	i = 0;
	while(tab[i] !=  0)
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}

int	no_leak_exit(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->isaac.img);
	mlx_destroy_image(data->mlx_ptr, data->wall.img);
	mlx_destroy_image(data->mlx_ptr, data->trap.img);
	mlx_destroy_image(data->mlx_ptr, data->coin.img);
	mlx_destroy_image(data->mlx_ptr, data->background.img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_double_array(data->map.map);
	exit(0);
}

void	render_map(t_data *data)
{
	int i;
	int j;

	i = 0;
	while (data->map.map[i] != 0)
	{	
		j = 0;
		while (data->map.map[i][j] != '\0')
		{
			if (data->map.map[i][j] == '1')
				 mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->wall.img, j*70, i*70);
			if (data->map.map[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->background.img, j*70, i*70);
			if (data->map.map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->isaac.img, j*70, i*70);
			if (data->map.map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->coin.img, j*70, i*70);
			if (data->map.map[i][j] == 'E' && data->map.open_exit == 1)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->trap.img, j*70, i*70);
			if (data->map.map[i][j] == 'E' && data->map.open_exit == 0)
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->background.img, j*70, i*70);
			j++;
		}
		i++;
	}
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 50, 0xFFFFFF, "score :");
}

int	render(t_data *data)
{
	if (data->win_ptr != NULL)
		render_map(data);
	return(0);
}

void	get_player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i] != 0)
	{
		j = 0;
		while(data->map.map[i][j] != '\0')
		{
			if (data->map.map[i][j] == 'P')
			{
				data->map.player_i = i;
				data->map.player_j = j;
			}
			j++;
		}
		i++;
	}
}

int	coe(t_data *data, char c)
{
	if (c == 'E' && data->map.open_exit == 1)
	{
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
	printf("%i\n", key);
	return (0);
}

// player mouvement                                               y
// collect item disepear                                          y
// no exit util no coin                                           y
// counter of moove                          
// close page when click on cross                        
// 
//

int	main(int argc, char **argv)
{
	t_data	data;
	
	if(check_map(&data, argv))
	{	
		free_double_array(data.map.map);
		return (write(1, "Error\n", 6));
	}

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.map.line_len*70, (data.map.line_nbr+1)*70, "force");
	data.map.open_exit = 0;
	data.isaac.img = mlx_xpm_file_to_image(data.mlx_ptr, "isaac.xpm", &data.isaac.width, &data.isaac.height);
	data.background.img = mlx_xpm_file_to_image(data.mlx_ptr, "background.xpm", &data.background.width, &data.background.height);
	data.wall.img = mlx_xpm_file_to_image(data.mlx_ptr, "wall.xpm", &data.wall.width, &data.wall.height);
	data.coin.img = mlx_xpm_file_to_image(data.mlx_ptr, "coin.xpm", &data.coin.width, &data.coin.height);
	data.trap.img = mlx_xpm_file_to_image(data.mlx_ptr, "trap.xpm", &data.trap.width, &data.trap.height);

	mlx_hook(data.win_ptr, 02, 1L<<0,&handle_key_input, &data);
	mlx_hook(data.win_ptr, 17, 0L, &no_leak_exit, &data);
	mlx_loop_hook(data.mlx_ptr, &render, &data);

	mlx_loop(data.mlx_ptr);
	return (0);
}
