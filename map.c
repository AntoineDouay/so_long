/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adouay <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 16:13:55 by adouay            #+#    #+#             */
/*   Updated: 2022/08/24 21:01:41 by adouay           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_ber(char *file)
{
	int n;

	n = ft_strlen(file);

	if (ft_strncmp(".ber", file + (n-4), 4) == 0)
		return (0);
	return (1);
}

void	parse_map(t_data *data, char *file)
{
	char	*line;
	char	*map_1d;
	int		fd;

	map_1d = NULL;
	fd = open(file, O_RDONLY, 0664);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		map_1d = ft_strjoin_pimped(map_1d, line);
		free(line);
	}
	data->map.map = ft_split(map_1d, '\n');
	free(map_1d);
	data->map.line_len = ft_strlen(data->map.map[0]);
	close(fd);
}

int	rectangular_map(char **map, int line_len, t_data *data)
{
	int	i;
	int tmp;

	i = 0;
	tmp = 0;
	while (map[i] != 0)
	{
		tmp = ft_strlen(map[i]);
		if (tmp != line_len)
			return (1);
		i++;
	}
	if (i < 3)
		return (1);
	data->map.line_nbr = i - 1; 
	return (0);
}

int	valid_carac_map(char **map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (map[i] != 0)
	{
		while(map[i][j] != '\0')
		{
			if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != 'P'
				&& map[i][j] != 'C' && map[i][j] != 'E')
				return (1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	surrounded_by_wall(char **map, int line_len, int line_nbr)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(map[i] != 0)
	{
		while(map[i][j] != '\0')
		{
			if (i == 0 || i == line_nbr)
				if (map[i][j] != '1')
					return (1);
			 if (j == 0 || j == line_len - 1)
				if (map[i][j] != '1')
					return (1);
			j++;
		}
		i++;
		j = 0;
	}
	return(0);
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
	int i;
	int	j;
	int p;
	int	c;
	int e;

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
			if (map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	return(valid(p, c, e));
}

int	check_map(t_data *data, char **argv)
{
//	if (map_file_exist())
	if (map_ber(argv[1]))
		return (printf("error ber"));
	parse_map(data, argv[1]);
	if (rectangular_map(data->map.map, data->map.line_len, data))
		return (printf("error rect"));
	if (valid_carac_map(data->map.map))
		return (printf("error carac"));
	if (surrounded_by_wall(data->map.map, data->map.line_len, data->map.line_nbr))
		return (printf("error wall"));
	if (check_carac(data->map.map))
		return (printf("error only carac"));
	return (0);
}
/*
TO DO 

check file exist
check file .ber
check line len map            y
check illegal carac           y
check line minimum 3          y
check map surrounder by wall  y
check carac
	- one exit
	- one start pose
	- at least one collectible

Error\n
FREEEEEEEEEEEEE
*/
