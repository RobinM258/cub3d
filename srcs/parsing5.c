/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:13:27 by romartin          #+#    #+#             */
/*   Updated: 2024/02/05 17:22:52 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	good_value(char *line)
{
	char	*str;
	char	*ret;

	str = redef_jsp(line);
	ret = no_more_space_bis(str);
	if (ft_isdigit(str) == 1 || ft_atoi(str) < 0
		|| ft_atoi(str) > 255 || ft_isdigitnospace(ret) == 1)
	{
		free(ret);
		free(str);
		return (1);
	}
	free (ret);
	free (str);
	return (0);
}

int	check_player(char **map)
{
	int	i;
	int	y;
	int	p;

	if (!map)
		return (0);
	i = 0;
	y = 0;
	p = 0;
	while (map[y])
	{
		while (map[y][i])
		{
			if (map[y][i] == 'N' || map[y][i] == 'E'
				|| map[y][i] == 'W' || map[y][i] == 'S')
				p++;
			i++;
		}
		i = 0;
		y++;
	}
	if (p != 1)
		return (1);
	return (0);
}

char	**map_fill_bis(char *av)
{
	char	**map;
	char	**map_fill;
	int		i;

	i = 0;
	map = find_map(av);
	if (!map)
		return (NULL);
	map_fill = malloc(sizeof(char *) * (tablen(map) + 1));
	if (!map)
		return (NULL);
	while (map[i])
	{
		map_fill[i] = str_fill(map[i], map);
		i++;
	}
	map_fill[i] = NULL;
	free_tab(map);
	return (map_fill);
}

int	check_sign_map(char **map)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (map[y])
	{
		while (map[y][x])
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != 'N'
				&& map[y][x] != 'S' && map[y][x] != 'E' && map[y][x] != 'W'
				&& map[y][x] != '\n' && map[y][x] != ' ')
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}
