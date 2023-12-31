#include "cub3d.h"

void init_map(t_game *game)
{
    int fd;
    int i;
    char *str;

    i = 0;
    fd = open("maps/test.cub", O_RDONLY);
    str = get_next_line(fd);
    while (str)
    {
        free(str);
        str = get_next_line(fd);
        i++;
    }
    close(fd);
    game->map = malloc(sizeof(char *) * (i + 1));
    i = 0;
    fd = open("maps/test.cub", O_RDONLY);
    str = get_next_line(fd);
    while (str)
    {

        game->map[i] = str;
        str = get_next_line(fd);
        i++;
    }
    game->map[i] = NULL;
}
void ft_put_pixel(t_game *game, float x, float y, uint32_t color)
{
    int i;
    int j;

    j = y * 32;
    x = x * 32;
    y = y * 32;
    i = x;
    while (j < y + 32)
    {
        i = x;
        while (i < x + 32)
        {
            mlx_put_pixel(game->bg, i , j, color);
            i++;
        }
        j++;
    }
}

void act_map(t_game *game)
{
    int i;
    int j;

    i = 0;
    j = 0;
    mlx_delete_image(game->mlx, game->bg);
    game->bg = mlx_new_image(game->mlx, 1024, 1024);
    mlx_image_to_window(game->mlx, game->bg, 0, 0);
    while (game->map[i])
    {
        j = 0;
        while(game->map[i][j])
        {
            if (game->map[i][j] == '1')
                ft_put_pixel(game, j, i, 0x55555FF);                
            j++;
        }
        ft_put_pixel(game, game->y_size, game->x_size, 0x66666FF);
        i++;
    }
}

void print_map(t_game *game)
{
    init_map(game);
    int i;
    int j;

    i = 0;
    j = 0;
    game->bg = mlx_new_image(game->mlx, 1024, 1024);
    mlx_image_to_window(game->mlx, game->bg, 0, 0);
    while (game->map[i])
    {
        j = 0;
        while(game->map[i][j])
        {
            if (game->map[i][j] == '1')
                ft_put_pixel(game, j, i, 0x55555FF);
            if (game->map[i][j] == '2')
            {
                game->x_size = i;
                game->y_size = j;
                printf("x = %f y = %f\n", game->x_size, game->y_size);  
                ft_put_pixel(game, j, i, 0x66666FF);
            }
                
            j++;
        }
        i++;
    }
}