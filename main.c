/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:34:10 by adouay            #+#    #+#             */
/*   Updated: 2022/08/24 21:10:19 by adouay           ###   ########.fr       */
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

void	no_leak_exit(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->isaac.img);
	mlx_destroy_image(data->mlx_ptr, data->wall.img);
	mlx_destroy_image(data->mlx_ptr, data->coin.img);
	mlx_destroy_image(data->mlx_ptr, data->background.img);
	free_double_array(data->map.map);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;

}

void	render_map(t_data *data)
{
	int i;
	int j;

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
			j++;
		}
		i++;
	}
}

int	render(t_data *data)
{
	if (data->win_ptr != NULL)
		render_map(data);
	return(0);
}

int	handle_key_input(int key, t_data *data)
{
	if (key == 65307) // ESCAPE
		no_leak_exit(data);
	if (key == 65362)
//		player_moove()
	if (key == 65361)
	if (key == 65364)
	if (key == 65363)
	printf("%i\n", key);
	return (0);
}

// player mouvement
// collect item disepear
// no exit util no coin
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
	data.isaac.img = mlx_xpm_file_to_image(data.mlx_ptr, "isaac.xpm", &data.isaac.width, &data.isaac.height);
	data.background.img = mlx_xpm_file_to_image(data.mlx_ptr, "background.xpm", &data.background.width, &data.background.height);
	data.wall.img = mlx_xpm_file_to_image(data.mlx_ptr, "wall.xpm", &data.wall.width, &data.wall.height);
	data.coin.img = mlx_xpm_file_to_image(data.mlx_ptr, "coin.xpm", &data.coin.width, &data.coin.height);

	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_key_hook(data.win_ptr, &handle_key_input, &data);

	mlx_loop(data.mlx_ptr);

	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);
	return (0);
}
