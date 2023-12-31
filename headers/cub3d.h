#ifndef CUB3D_H
#define CUB3D_H

#include <stdarg.h>
#include <fcntl.h>
#include "libft.h"
#include "structs.h"

extern t_game *game;

void print_map(t_game *game);
void act_map(t_game *game);
void key_hook(mlx_key_data_t keydata, void *param);
void loop_hook(void *param);
void ft_movement(t_game * game, char key);

#endif