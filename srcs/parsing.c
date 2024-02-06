/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 13:06:20 by romartin          #+#    #+#             */
/*   Updated: 2024/02/05 17:54:14 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_texture(char *ext, mlx_texture_t **texture, int fdn[0])
{
	char	*str;
	char	*red;
	char	*line;

	str = get_next_line(fdn[1]);
	while (str && line_map(str) != 0)
	{
		red = no_more_space_bis(str);
		line = redef_line_bis(str);
		if (ft_strncmp(red, ext, 3) == 0 && ft_strlen(red) >= 3)
		{
			if (check_link(line) == 1 || check_nb_arg(str) == 1)
				return (error_walls(str, red, line));
			if (fdn[0] == 0)
				*texture = mlx_load_png(line);
			fdn[0]++;
		}
		error_walls(str, red, line);
		str = get_next_line(fdn[1]);
	}
	free(str);
	if (fdn[0] != 1)
		return (1);
	return (0);
}

int	check_walls(char *file, t_game *game)
{
	int	fdn[2];

	fdn[0] = 0;
	fdn[1] = open(file, O_RDONLY);
	if (check_texture("SO ", &game->w_south, fdn) == 1)
		return (1);
	close(fdn[1]);
	fdn[1] = open(file, O_RDONLY);
	fdn[0] = 0;
	if (check_texture("NO ", &game->w_north, fdn) == 1)
		return (1);
	close(fdn[1]);
	fdn[1] = open(file, O_RDONLY);
	fdn[0] = 0;
	if (check_texture("EA ", &game->w_east, fdn) == 1)
		return (1);
	close(fdn[1]);
	fdn[1] = open(file, O_RDONLY);
	fdn[0] = 0;
	if (check_texture("WE ", &game->w_west, fdn) == 1)
		return (1);
	close(fdn[1]);
	return (0);
}

int	check_number(char *file, char *ext, uint32_t *color, int nb)
{
	int		fd;
	char	*str;

	*color = 0;
	fd = open(file, O_RDONLY);
	str = get_next_line(fd);
	while (str && line_map(str) != 0)
	{
		if (ft_strncmp(str, ext, 1) == 0)
		{
			if (check_value(str) == 1)
			{
				free (str);
				return (1);
			}
			*color = str_to_color(parse_strtocolor(str));
			nb++;
		}
		free (str);
		str = get_next_line(fd);
	}
	free(str);
	if (nb != 1)
		return (1);
	return (0);
}

int	check_floor(char *file, t_game *game)
{
	if (check_number(file, "C", &game->roof, 0) == 1)
		return (1);
	if (check_number(file, "F", &game->floor, 0) == 1)
		return (1);
	return (0);
}

int	parsing(char *path_file, t_game *game)
{
	char	**map;
	char	**map_fil;

	map = find_map(path_file);
	map_fil = map_fill_bis(path_file);
	if (check_player(map_fil) == 1)
		return (error_parsing(map, map_fil, "Erreur sur la map"));
	if (true_ext_map(path_file) == 1)
		return (error_parsing(map, map_fil, "Erreur d'extention du fichier"));
	if (!map)
		return (error_parsing(map, map_fil, "Erreur fichier inexistant"));
	if (check_walls(path_file, game) == 1)
		return (error_parsing(map, map_fil, "Erreur de texture"));
	if (check_floor(path_file, game) == 1)
		return (error_parsing(map, map_fil, "Erreur de sol ou de plafond"));
	if (true_map(map_fil) == 1 || check_sign_map(map))
		return (error_parsing(map, map_fil, "Erreur sur la map"));
	free_tab(map_fil);
	free_tab(map);
	return (0);
}
