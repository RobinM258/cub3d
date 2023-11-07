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
    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(game->mlx);
    if (mlx_is_key_down(game->mlx, MLX_KEY_W))
        ft_movement(game, 'w');
    if (mlx_is_key_down(game->mlx, MLX_KEY_S))
        ft_movement(game, 's');
    if (mlx_is_key_down(game->mlx, MLX_KEY_A))
        ft_movement(game, 'a');
    if (mlx_is_key_down(game->mlx, MLX_KEY_D))
        ft_movement(game, 'd');
    act_map(game);
}