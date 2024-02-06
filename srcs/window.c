/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:28:02 by dgoubin           #+#    #+#             */
/*   Updated: 2024/02/05 17:07:26 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	chose_texture(t_game *game, int ns, float angle)
{
	if (!ns)
	{
		if (angle > 0 && angle < M_PI)
			game->actual_text = game->w_south;
		else
			game->actual_text = game->w_north;
	}
	else
	{
		if (angle > M_PI / 2 && angle < 3 * M_PI / 2)
			game->actual_text = game->w_west;
		else
			game->actual_text = game->w_east;
	}
	return (1);
}

uint32_t	get_text_img(t_game *game, int wHeight, double wallSize, float x)
{
	uint32_t	color;
	double		r;
	uint8_t		*pix_tab;

	r = wallSize / game->actual_text->height;
	color = 0;
	pix_tab = game->actual_text->pixels;
	wHeight -= (HEIGHT / 2 - (wallSize / 2));
	wHeight /= r;
	if (wHeight >= (int)game->actual_text->height)
		wHeight = game->actual_text->height;
	if (x >= game->actual_text->width)
		x = (int)floor(x) % game->actual_text->width + (floor(x) - x);
	color = color | (pix_tab[(int)((game->actual_text->width * (x - floor(x))))
			*4 + (wHeight * game->actual_text->height * 4)] << 24);
	color = color | (pix_tab[(int)((game->actual_text->width * (x - floor(x))))
			*4 + (wHeight * game->actual_text->height * 4) + 1] << 16);
	color = color | (pix_tab[(int)((game->actual_text->width * (x - floor(x))))
			*4 + (wHeight * game->actual_text->height * 4) + 2] << 8);
	color = color | (pix_tab[(int)((game->actual_text->width * (x - floor(x))))
			*4 + (wHeight * game->actual_text->height * 4) + 3]);
	return (color);
}

float	next_point(t_game *game, float angle, char point)
{
	float	x;
	float	y;

	angle += 0.0174533 / 8;
	x = game->player.x;
	y = game->player.y;
	while (game->map[(int)y][(int)x] != '1')
	{
		x += cos(angle) * 0.001;
		y += sin(angle) * 0.001;
	}
	if (point == 'x')
		return (x);
	return (y);
}

void	raycast(t_game *game)
{
	int	i;
	int	r;

	i = 0;
	mlx_delete_image(game->mlx, game->raycast);
	game->ray.angle = game->player.angle
		- 30 * 0.0174533 - 0.0174533 / game->res;
	find_next_wall(game);
	save(game);
	game->ray.cpt = 0;
	game->raycast = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	while (i++ < FOV * game->res)
	{	
		find_next_wall(game);
		r = 0;
		while (r < (int)(WIDTH / (FOV * (game->res * game->os))))
			draw_img(game, r++);
		save(game);
	}
	mlx_image_to_window(game->mlx, game->raycast, 0, 0);
}

void	init_window(t_game *game)
{
	game->raycast = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	mlx_image_to_window(game->mlx, game->raycast, 0, 0);
	mlx_close_hook(game->mlx, close_hook, game);
	mlx_key_hook(game->mlx, key_hook, game);
	mlx_loop_hook(game->mlx, loop_hook, game);
	mlx_loop(game->mlx);
}
