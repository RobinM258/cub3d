/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 18:59:11 by dgoubin           #+#    #+#             */
/*   Updated: 2024/02/05 17:06:16 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	search_player_pos(t_game *game, int i, int j)
{
	while (game->map[j])
	{
		i = 0;
		while (i < game->map_xsize - 1)
		{
			if (game->map[j][i] == 'N' || game->map[j][i] == 'S'
				|| game->map[j][i] == 'E' || game->map[j][i] == 'W')
			{
				game->player.x = i + 0.5;
				game->player.y = j + 0.5;
				if (game->map[j][i] == 'N')
					game->player.angle = 3 * M_PI / 2;
				if (game->map[j][i] == 'S')
					game->player.angle = M_PI / 2;
				if (game->map[j][i] == 'E')
					game->player.angle = 0;
				if (game->map[j][i] == 'W')
					game->player.angle = M_PI;
			}
			i++;
		}
		j++;
	}
}

void	collision(t_game *game, float col[2], float x, float y)
{
	int		t;

	t = 0;
	if (game->map[(int)(y + col[1] * 2)][(int)(x + col[0] * 2)] != '1')
	{
		if (col[0] > 0 && col[1] > 0 && game->map[(int)(y + 0.4)]
			[(int)(x + 0.4)] != '1')
			t = 1;
		else if (col[0] < 0 && col[1] > 0
			&& game->map[(int)(y + 0.4)][(int)(x - 0.4)] != '1')
			t = 1;
		else if (col[0] > 0 && col[1] < 0
			&& game->map[(int)(y - 0.4)][(int)(x + 0.4)] != '1')
			t = 1;
		else if (col[0] < 0 && col[1] < 0
			&& game->map[(int)(y - 0.4)][(int)(x - 0.4)] != '1')
			t = 1;
	}
	if (t)
	{
		game->player.x += col[0];
		game->player.y += col[1];
	}
}

float	*get_move(t_game *game, float col[2])
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W))
	{
		col[0] = cos(game->player.angle) * 0.2;
		col[1] = sin(game->player.angle) * 0.2;
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
	{
		col[0] = -cos(game->player.angle) * 0.2;
		col[1] = -sin(game->player.angle) * 0.2;
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
	{
		col[0] = -sin(game->player.angle) * 0.2;
		col[1] = cos(game->player.angle) * 0.2;
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
	{
		col[0] = sin(game->player.angle) * 0.2;
		col[1] = -cos(game->player.angle) * 0.2;
	}
	return (col);
}
