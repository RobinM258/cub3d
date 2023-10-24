#include "cub3d.h"

void key_hook(mlx_key_data_t keydata, void *param)
{
    t_game *game = param;
    if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
        mlx_close_window(game->mlx);
    if (keydata.key == MLX_KEY_Z && keydata.action == MLX_PRESS)
        printf("test\n");

}