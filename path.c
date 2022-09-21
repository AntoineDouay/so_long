/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:28:37 by adouay            #+#    #+#             */
/*   Updated: 2022/09/21 12:22:55 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_result(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'C' || map[i][j] == 'E')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	map_is_filled(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				if (map[i - 1][j] == '0' || map[i - 1][j] == 'C')
					return (1);
				if (map[i + 1][j] == '0' || map[i + 1][j] == 'C')
					return (1);
				if (map[i][j - 1] == '0' || map[i][j - 1] == 'C')
					return (1);
				if (map[i][j + 1] == '0' || map[i][j + 1] == 'C')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	fill_this_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] == 'P')
			{
				if (map[i - 1][j] != '1' && map[i - 1][j] != 'M')
					map[i - 1][j] = 'P';
				if (map[i + 1][j] != '1' && map[i + 1][j] != 'M')
					map[i + 1][j] = 'P';
				if (map[i][j - 1] != '1' && map[i][j - 1] != 'M')
					map[i][j - 1] = 'P';
				if (map[i][j + 1] != '1' && map[i][j + 1] != 'M')
					map[i][j + 1] = 'P';
			}
			j++;
		}
		i++;
	}
}

char	**map_cpy(t_data *data)
{
	int		i;
	int		j;
	char	**map_cpy;

	i = 0;
	map_cpy = malloc(sizeof(char *) * (data->map.line_nbr + 2));
	if (!map_cpy)
		return (NULL);
	while (data->map.map[i] != 0)
	{
		j = 0;
		map_cpy[i] = ft_strdup(data->map.map[i]);
		while (map_cpy[i][j] != '\0')
		{
			if (map_cpy[i][j] == 'E')
				map_cpy[i][j] = 'C';
			j++;
		}
		i++;
	}
	map_cpy[i] = 0;
	return (map_cpy);
}

void	check_valid_path(t_data *data)
{
	char	**map;

	map = map_cpy(data);
	if (map == NULL)
	{
		ft_printf("malloc error\n");
		free_double_array(data->map.map);
		exit(0);
	}
	while (map_is_filled(map))
		fill_this_map(map);
	if (check_result(map))
	{
		ft_printf("Error\n");
		ft_printf("no path\n");
		free_double_array(data->map.map);
		free_double_array(map);
		exit(0);
	}
	free_double_array(map);
	return ;
}
