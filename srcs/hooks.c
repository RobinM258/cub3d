/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:01:27 by dgoubin           #+#    #+#             */
/*   Updated: 2024/02/05 18:24:42 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	loop_hook(void *param)
{
	t_game	*game;
	float	xymove[2];

	xymove[0] = 0;
	xymove[1] = 0;
	game = param;
	if (mlx_is_key_down(game->mlx, MLX_KEY_RIGHT))
	{
		game->player.angle += 0.1;
		if (game->player.angle > 2 * M_PI)
			game->player.angle -= 2 * M_PI;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_LEFT))
	{
		game->player.angle -= 0.1;
		if (game->player.angle < 0)
			game->player.angle += 2 * M_PI;
	}
	get_move(game, xymove);
	collision(game, xymove, game->player.x, game->player.y);
	raycast(game);
}

void	key_hook(mlx_key_data_t data, void *param)
{
	t_game	*game;

	game = param;
	if (data.action == MLX_PRESS && data.key == MLX_KEY_ESCAPE)
	{
		free_tab(game->map);
		mlx_close_window(game->mlx);
		mlx_terminate(game->mlx);
		exit(0);
	}
	if (data.action == MLX_PRESS && data.key == MLX_KEY_KP_ADD)
		if (game->res < 4 && game->os != 2)
			game->res *= 2;
	if (data.action == MLX_PRESS && data.key == MLX_KEY_KP_SUBTRACT)
		if (game->res > 1)
			game->res /= 2;
	if (data.action == MLX_PRESS && data.key == MLX_KEY_O)
	{
		if (game->os == 1)
			game->os = 2;
		else
			game->os = 1;
	}
}

void	close_hook(void *param)
{
	t_game	*game;

	game = param;
	free_tab(game->map);
	mlx_delete_texture(game->w_east);
	mlx_delete_texture(game->w_west);
	mlx_delete_texture(game->w_south);
	mlx_delete_texture(game->w_north);
	mlx_close_window(game->mlx);
	exit(0);
}
