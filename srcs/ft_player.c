#include "cub3d.h"

void ft_movement(t_game *game, char key)
{
    if (key == 'w')
    {
       game->x_size = game->x_size - 0.1;
        printf("x = %f y = %f\n", game->x_size, game->y_size);
    }
    if (key == 's')
    {
        game->x_size = game->x_size + 0.1;
        printf("x = %f y = %f\n", game->x_size, game->y_size);
    }
    if (key == 'a')
    {
        game->y_size = game->y_size - 0.1;
        printf("x = %f y = %f\n", game->x_size, game->y_size);                            
    }
    if (key == 'd')
    {
        game->y_size = game->y_size + 0.1;
        printf("x = %f y = %f\n", game->x_size, game->y_size);                            
    }
}
