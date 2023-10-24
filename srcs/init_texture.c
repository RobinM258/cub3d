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
void ft_put_pixel(t_game *game, int x, int y)
{
    int i;
    int j;

    j = y;
    x = x + 64;
    y = y + 64;
    i = x;
    while (j < y)
    {
        x = x -64;
        while (i < x)
        {
            mlx_put_pixel(game->bg, i , j, 0x666666FF);
            i++;
        }
        j++;
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
            printf("i = %d j = %d\n", i, j);
            ft_put_pixel(game, i, j);
            j++;
        }
        i++;
    }
}