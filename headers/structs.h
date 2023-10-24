#ifndef STRUCTS_H
#define STRUCTS_H

#include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_game
{
    mlx_t   *mlx;
    mlx_t           *win;
    mlx_image_t     *bg;
    mlx_image_t *wall;
    char    **map;
    int     y_size;
    int     x_size;

} t_game;


#endif