/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:42:22 by romartin          #+#    #+#             */
/*   Updated: 2024/01/30 17:43:46 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*redef_line(char *str, int lenght)
{
	char	*ret;
	int		i;

	i = 0;
	ret = malloc(sizeof(char) * (lenght + 1));
	if (!ret)
		return (NULL);
	while (i < lenght)
	{
		if (str[i] == ' ' || str[i] == '\n')
			ret[i] = '-';
		if (str[i])
			ret[i] = str[i];
		if (!str[i] && i < lenght)
			ret[i] = '-';
		i++;
	}
	free(str);
	ret[i] = '\0';
	return (ret);
}

int	longest_line(char **map)
{
	int	max;
	int	i;

	max = 0;
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) > max)
			max = ft_strlen(map[i]);
		i++;
	}
	return (max);
}

char	*str_fill(char *str, char **map)
{
	char	*ret;
	int		i;
	int		max;
	int		line_size;

	if (!str)
		return (NULL);
	line_size = ft_strlen(str);
	i = 0;
	max = longest_line(map);
	ret = malloc(sizeof(char) * (max + 1));
	if (!ret)
		return (NULL);
	while (i < max)
	{
		if (i >= line_size || str[i] == ' ')
			ret[i] = '-';
		else if (str[i] != '\0' && str[i] != ' ')
			ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}

char	*ft_one(int line_size)
{
	int		i;
	char	*ret;

	i = 0;
	ret = malloc(line_size + 1);
	while (i < line_size)
		ret[i++] = '1';
	ret[i] = '\0';
	return (ret);
}

char	**map_fill(char *av)
{
	char	**map;
	char	**map_fill;
	int		i;

	i = 0;
	map = find_map(av);
	map_fill = malloc(sizeof(char *) * (tablen(map) + 1));
	if (!map)
		return (NULL);
	while (map[i])
	{
		if (i == 0 || i == tablen(map) - 1)
			map_fill[i] = ft_one(longest_line(map));
		else
		{
			map_fill[i] = str_fill(map[i], map);
			map_fill[i][0] = '1';
			map_fill[i][longest_line(map) - 1] = '1';
		}
		i++;
	}
	map_fill[i] = NULL;
	free_tab(map);
	return (map_fill);
}
