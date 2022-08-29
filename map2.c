/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <adouay@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 04:38:42 by adouay            #+#    #+#             */
/*   Updated: 2022/08/29 05:22:06 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_player_pos(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.map[i] != 0)
	{
		j = 0;
		while (data->map.map[i][j] != '\0')
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

int	map_ber(char *file)
{
	int	n;

	n = ft_strlen(file);
	if (n < 5)
		return (1);
	if (ft_strncmp(".ber", file + (n - 4), 4) == 0)
		return (0);
	return (1);
}

int	valid_carac_map(t_data *data, char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i] != 0)
	{
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
			{
				data->map.exit_pos_i = i;
				data->map.exit_pos_j = j;
			}
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
				&& map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'M')
				return (1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	valid(int p, int c, int e)
{
	if (p != 1)
		return (1);
	if (e != 1)
		return (1);
	if (c == 0)
		return (1);
	return (0);
}

int	check_carac(char **map)
{
	int	i;
	int	j;
	int	p;
	int	c;
	int	e;

	i = 0;
	p = 0;
	c = 0;
	e = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'E')
				e++;
			if (map[i][j] == 'P')
				p++;
			if (map[i][j++] == 'C')
				c++;
		}
		i++;
	}
	return (valid(p, c, e));
}
