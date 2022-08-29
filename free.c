/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 05:56:18 by adouay            #+#    #+#             */
/*   Updated: 2022/08/29 05:56:54 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_double_array(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}

int	no_leak_exit(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->isaac_f.img);
	mlx_destroy_image(data->mlx_ptr, data->isaac_b.img);
	mlx_destroy_image(data->mlx_ptr, data->isaac_l.img);
	mlx_destroy_image(data->mlx_ptr, data->isaac_r.img);
	mlx_destroy_image(data->mlx_ptr, data->enemies.img);
	mlx_destroy_image(data->mlx_ptr, data->wall.img);
	mlx_destroy_image(data->mlx_ptr, data->trap.img);
	mlx_destroy_image(data->mlx_ptr, data->coin.img);
	mlx_destroy_image(data->mlx_ptr, data->bg.img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	data->win_ptr = NULL;
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_double_array(data->map.map);
	exit(0);
}
