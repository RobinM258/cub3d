#ifndef STRUCTS_H
#define STRUCTS_H

#include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_player
{
    int x;
    int y;

} t_player;

typedef struct s_game
{
    mlx_t   *mlx;
    mlx_t           *win;
    mlx_image_t     *bg;
    mlx_image_t *wall;
    char    **map;
    float    y_size;
    float    x_size;

} t_game;


#endif