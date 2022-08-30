/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 05:56:18 by adouay            #+#    #+#             */
/*   Updated: 2022/08/30 12:41:27 by adouay           ###   ########.fr       */
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

void	set_img_np(t_data *data, t_img *img, char *file)
{
	img->img = mlx_xpm_file_to_image(data->mlx_ptr,
			file, &img->width, &img->height);
	if (!img->img)
		no_leak_exit(data);
}

void	destroy_image(t_data *data, t_img *img)
{
	if (img->img)
		mlx_destroy_image(data->mlx_ptr, img->img);
}

int	no_leak_exit(t_data *data)
{
	if (data->win_ptr && data->mlx_ptr)
	{
		destroy_image(data, &data->isaac_f);
		destroy_image(data, &data->isaac_b);
		destroy_image(data, &data->isaac_l);
		destroy_image(data, &data->isaac_r);
		destroy_image(data, &data->enemies);
		destroy_image(data, &data->wall);
		destroy_image(data, &data->trap);
		destroy_image(data, &data->coin);
		destroy_image(data, &data->bg);
	}
	if (data->win_ptr && data->mlx_ptr)
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	free_double_array(data->map.map);
	exit(0);
}
