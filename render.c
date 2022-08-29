/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 03:40:27 by adouay            #+#    #+#             */
/*   Updated: 2022/08/29 05:51:18 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_wall(t_data *data, char c, int i, int j)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->wall.img, j * 50, i * 50);
}

void	render_step(t_data *data)
{
	char	*step;

	step = ft_itoa(data->step);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 30, 35, 0xFFFFFF, "score :");
	mlx_string_put(data->mlx_ptr, data->win_ptr, 80, 35, 0xFFFFFF, step);
	free(step);
}

void	render_isaac(t_data *data, char c, int i, int j)
{
	if (c == 'P')
	{
		if (data->isaac_up == 1)
			mlx_put_image_to_window(data->mlx_ptr,
				data->win_ptr, data->isaac_b.img, j * 50, i * 50);
		if (data->isaac_down == 1)
			mlx_put_image_to_window(data->mlx_ptr,
				data->win_ptr, data->isaac_f.img, j * 50, i * 50);
		if (data->isaac_left == 1)
			mlx_put_image_to_window(data->mlx_ptr,
				data->win_ptr, data->isaac_l.img, j * 50, i * 50);
		if (data->isaac_right == 1)
			mlx_put_image_to_window(data->mlx_ptr,
				data->win_ptr, data->isaac_r.img, j * 50, i * 50);
	}
}

void	render_map(t_data *data, char c, int i, int j)
{
	if (c == '0')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->bg.img, j * 50, i * 50);
	if (c == 'C')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->coin.img, j * 50, i * 50);
	if (c == 'M')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->enemies.img, j * 50, i * 50);
	if (c == 'E' && data->map.open_exit == 1)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->trap.img, j * 50, i * 50);
	if (c == 'E' && data->map.open_exit == 0)
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->bg.img, j * 50, i * 50);
}

int	render(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i] != 0)
	{
		j = 0;
		while (data->map.map[i][j] != '\0')
		{
			render_wall(data, data->map.map[i][j], i, j);
			render_map(data, data->map.map[i][j], i, j);
			render_isaac(data, data->map.map[i][j], i, j);
			j++;
		}
		i++;
	}
	render_step(data);
	return (0);
}
