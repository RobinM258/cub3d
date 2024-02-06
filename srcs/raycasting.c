/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:44:28 by dgoubin           #+#    #+#             */
/*   Updated: 2024/02/02 20:07:46 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	rlc(t_game *game)
{
	if (fabs(game->ray.savedist
			-dist(game->player.x, game->player.y, game->ray.x, game->ray.y)
			*cos(game->player.angle - game->ray.angle)) < 0.5)
		game->ray.blop = fabs(game->ray.savex - game->ray.x)
			< fabs(game->ray.savey - game->ray.y);
	else
		game->ray.blop = fabs(game->ray.x
				- next_point(game, game->ray.angle, 'x'))
			< fabs(game->ray.y - next_point(game, game->ray.angle, 'y'));
}

void	find_next_wall(t_game *game)
{
	if (game->ray.angle < 0)
		game->ray.angle += 2 * M_PI;
	if (game->ray.angle > 2 * M_PI)
		game->ray.angle -= 2 * M_PI;
	game->ray.x = game->player.x;
	game->ray.y = game->player.y;
	while (game->map[(int)game->ray.y][(int)game->ray.x] != '1')
	{
		game->ray.x += cos(game->ray.angle) * 0.001;
		game->ray.y += sin(game->ray.angle) * 0.001;
	}
	game->ray.wallsize = 1000
		/ (dist(game->player.x, game->player.y, game->ray.x, game->ray.y)
			*cos(game->player.angle - game->ray.angle));
	if (game->ray.wallsize > HEIGHT)
		game->ray.disp_wallsize = HEIGHT;
	else
		game->ray.disp_wallsize = game->ray.wallsize;
	rlc(game);
}

void	draw_img(t_game *game, int r)
{
	int	i;

	i = 0;
	while (i < HEIGHT / 2 - (game->ray.disp_wallsize / 2))
		mlx_put_pixel(game->raycast, game->ray.cpt + r, i++, game->roof);
	i = HEIGHT / 2 - (game->ray.disp_wallsize / 2);
	while (i < HEIGHT / 2 + (game->ray.disp_wallsize / 2))
	{
		chose_texture(game, game->ray.blop, game->ray.angle);
		if (game->ray.blop)
			mlx_put_pixel(game->raycast, game->ray.cpt + r, i,
				get_text_img(game, i, game->ray.wallsize, game->ray.y));
		else
			mlx_put_pixel(game->raycast, game->ray.cpt + r, i,
				get_text_img(game, i, game->ray.wallsize, game->ray.x));
		i++;
	}
	i = HEIGHT / 2 + (game->ray.disp_wallsize / 2);
	while (i < HEIGHT)
		mlx_put_pixel(game->raycast, game->ray.cpt + r, i++, game->floor);
}

void	save(t_game *game)
{
	game->ray.savedist = dist(game->player.x,
			game->player.y, game->ray.x, game->ray.y)
		*cos(game->player.angle - game->ray.angle);
	game->ray.angle += 0.0174533 / game->res;
	game->ray.cpt += (int)(WIDTH / (FOV * game->res));
	game->ray.savex = game->ray.x;
	game->ray.savey = game->ray.y;
}
