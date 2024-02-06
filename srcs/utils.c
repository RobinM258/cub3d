/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:54:49 by dgoubin           #+#    #+#             */
/*   Updated: 2024/02/02 20:31:24 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	tablen(char **str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	init_game(t_game *game, char *av)
{
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3d", false);
	game->map = map_fill(av);
	game->map_xsize = ft_strlen(game->map[0]);
	game->map_ysize = tablen(game->map);
	game->os = 1;
	game->res = 1;
	search_player_pos(game, 0, 0);
	game->player.angle += 0.00000000000001f;
}

uint32_t	str_to_color(char *str)
{
	char		**tmp;
	int			i;
	uint32_t	color;

	color = 0;
	i = 0;
	tmp = ft_split(str, ',');
	while (tmp[i])
	{
		color = color | (ft_atoi(tmp[i]) << (24 - 8 * i));
		i++;
	}
	free_tab(tmp);
	color = color | 0xFF;
	free(str);
	return (color);
}

float	dist(float x1, float y1, float x2, float y2)
{
	return (sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}
