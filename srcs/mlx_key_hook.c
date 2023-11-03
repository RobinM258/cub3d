#include "cub3d.h"

void key_hook(mlx_key_data_t keydata, void *param)
{
    t_game  *game;

    game = param;
    (void)game;
    if (keydata.key == MLX_KEY_RIGHT && keydata.action != MLX_RELEASE)
    {
        return ;
    }
}

void loop_hook(void *param)
{
    t_game  *game;

    game = (t_game *)param;
  if (mlx_is_key_down(game->win, MLX_KEY_ESCAPE))
        mlx_close_window(game->mlx);
    if (mlx_is_key_down(game->mlx, MLX_KEY_W))
        ft_movement(game, 'w');
}