/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:42:22 by romartin          #+#    #+#             */
/*   Updated: 2024/01/30 17:45:49 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	line_map(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '1'
			&& str[i] != '0' && str[i] != '\n'
			&& str[i] != 'N' && str[i] != 'W'
			&& str[i] != 'S' && str[i] != 'E' && str[i] != '-')
			return (-1);
		if (str[i] == '1' || str[i] == '0')
			j++;
		i++;
	}
	if (j == 0)
		return (-1);
	return (0);
}

int	lenght_map(int fd)
{
	int		lenght;
	char	*str;

	lenght = 1;
	str = get_next_line(fd);
	while (str)
	{
		lenght++;
		free(str);
		str = get_next_line(fd);
	}
	return (lenght);
}

char	**map_gen(int fd, int lenght)
{
	char	**map;
	char	*str;
	int		i;

	i = 0;
	str = get_next_line(fd);
	map = malloc(sizeof(char *) * (lenght + 1));
	if (!map)
		return (NULL);
	while (str && line_map(str) != 0)
	{
		free(str);
		str = get_next_line(fd);
	}
	while (str)
	{
		map[i++] = str;
		str = get_next_line(fd);
	}
	map[i] = NULL;
	free (str);
	return (map);
}

char	**find_map(char *av)
{
	int		fd;
	int		fd2;
	char	*str;
	char	**map;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (NULL);
	fd2 = open(av, O_RDONLY);
	str = get_next_line(fd);
	while (str && line_map(str) != 0)
	{
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	map = map_gen(fd2, lenght_map(fd));
	return (map);
}
