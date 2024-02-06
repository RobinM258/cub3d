/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:48:59 by romartin          #+#    #+#             */
/*   Updated: 2024/02/05 17:12:23 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_coord_bis(char **map, int y, int x)
{
	if (map[y][x + 1] != '0' && map[y][x + 1] != '1' && map[y][x + 1] != '1'
		&& map[y][x + 1] != 'N' && map[y][x + 1] != 'S'
		&& map[y][x + 1] != 'E' && map[y][x + 1] != 'W')
		return (1);
	if (x == 0 || !map[y + 1] || (map[y + 1][x - 1] != '0'
		&& map[y + 1][x - 1] != '1' && map[y + 1][x - 1] != 'N'
		&& map[y + 1][x - 1] != 'S' && map[y + 1][x - 1] != 'E'
		&& map[y + 1][x - 1] != 'W'))
		return (1);
	if (!map[y + 1] || (map[y + 1][x] != '0' && map[y + 1][x] != '1'
		&& map[y + 1][x] != 'N' && map[y + 1][x] != 'S'
		&& map[y + 1][x] != 'E' && map[y + 1][x] != 'W'))
		return (1);
	if (!map[y + 1] || (map[y + 1][x + 1] != '0'
		&& map[y + 1][x + 1] != '1' && map[y + 1][x + 1] != 'N'
		&& map[y + 1][x + 1] != 'S' && map[y + 1][x + 1] != 'E'
		&& map[y + 1][x + 1] != 'W'))
		return (1);
	return (0);
}

int	check_coord(char **map, int y, int x)
{
	if (y == 0 || x == 0 || (map[y - 1][x - 1] != '0'
		&& map[y - 1][x - 1] != '1' && map[y - 1][x - 1] != 'N'
		&& map[y - 1][x - 1] != 'S' && map[y - 1][x - 1] != 'E'
		&& map[y - 1][x - 1] != 'W'))
		return (1);
	if (y == 0 || (map[y - 1][x] != '0' && map[y - 1][x] != '1'
		&& map[y - 1][x] != 'N' && map[y - 1][x] != 'S'
		&& map[y - 1][x] != 'E' && map[y - 1][x] != 'W'))
		return (1);
	if (y == 0 || (map[y - 1][x + 1] != '0'
		&& map[y - 1][x + 1] != '1' && map[y - 1][x + 1] != 'N'
		&& map[y - 1][x + 1] != 'S' && map[y - 1][x + 1] != 'E'
		&& map[y - 1][x + 1] != 'W'))
		return (1);
	if (x == 0 || (map[y][x - 1] != '0' && map[y][x - 1] != '1'
		&& map[y][x - 1] != 'N' && map[y][x - 1] != 'S'
		&& map[y][x - 1] != 'E' && map[y][x - 1] != 'W'))
		return (1);
	if (check_coord_bis(map, y, x) == 1)
		return (1);
	return (0);
}

int	true_map(char **map)
{
	int	x;
	int	y;
	int	error;

	x = -1;
	y = -1;
	error = 0;
	while (map[++y] != NULL)
	{
		while (map[y][++x])
		{
			if (map[y][x] != '-' && error == 1 && map[y][x] != '\n')
				return (1);
			if (map[y][x] == '0' || map[y][x] == 'N'
				|| map[y][x] == 'S' || map[y][x] == 'W' || map[y][x] == 'E')
				if (check_coord(map, y, x) == 1)
					return (1);
		}
		if (line_map(map[y]) != 0)
			error = 1;
		x = -1;
	}
	return (0);
}

int	true_ext_map(char *path_file)
{
	int	i;

	i = 0;
	while (path_file[i])
		i++;
	i--;
	if (path_file[i] != 'b' || path_file[i - 1] != 'u'
		|| path_file[i - 2] != 'c' || path_file[i - 3] != '.')
		return (1);
	return (0);
}

int	check_link(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
		i++;
	i--;
	while (str[i] && str[i] == ' ')
		i--;
	if (i < 4)
		return (1);
	if (str[i] != 'g' || str[i - 1] != 'n'
		|| str[i - 2] != 'p' || str[i - 3] != '.')
		return (1);
	if (access(str, R_OK) != 0)
		return (1);
	return (0);
}
