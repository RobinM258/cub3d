
#include "../headers/cub3d.h"

t_game *game;

int main (void)
{
    game = malloc(sizeof(t_game));
    if (!game)
        return (0);
    game->mlx = mlx_init(1024, 1024, "cub3d", true);
    print_map(game);
    mlx_key_hook(game->mlx, &key_hook, game);
    mlx_loop(game->mlx);
    return (0);
}
