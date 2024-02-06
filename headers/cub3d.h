/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:17:57 by romartin          #+#    #+#             */
/*   Updated: 2024/02/05 17:18:08 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <stdio.h>
# include "MLX42/MLX42.h"
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

# define WIDTH 960
# define HEIGHT 720
# define SPEED 5
# define FOV 60
# define TEXT_SIZE 64

typedef struct s_player {
	float	x;
	float	y;
	float	angle;
}	t_player;

typedef struct s_ray {
	double	x;
	double	y;
	double	savex;
	double	savey;
	int		cpt;
	float	angle;
	float	savedist;
	int		blop;
	double	wallsize;
	double	disp_wallsize;
}	t_ray;

typedef struct s_game {
	mlx_t			*mlx;
	t_player		player;
	mlx_image_t		*raycast;
	char			**map;
	mlx_texture_t	*actual_text;
	mlx_texture_t	*w_east;
	mlx_texture_t	*w_north;
	mlx_texture_t	*w_south;
	mlx_texture_t	*w_west;
	uint32_t		floor;
	uint32_t		roof;
	int				map_xsize;	
	int				map_ysize;
	t_ray			ray;
	int				res;
	int				os;
}	t_game;

void		init_window(t_game *game);
void		close_hook(void *param);
void		key_hook(mlx_key_data_t data, void *param);
void		loop_hook(void *param);
void		raycast(t_game *game);
char		**find_map(char *av);
int			tablen(char **str);
float		dist(float x1, float y1, float x2, float y2);
void		init_game(t_game *game, char *av);
uint32_t	str_to_color(char *str);
int			parsing(char *path_file, t_game *game);
int			true_map(char **map);
int			check_link(char *str);
int			true_ext_map(char *path_file);
int			error_walls(char *str, char *red, char *line);
int			error_parsing(char **map, char **map2, char *error);
int			line_map(char *str);
int			lenght_map(int fd);
char		**map_gen(int fd, int lenght);
char		**map_fill(char *av);
int			tablen(char **str);
void		free_tab(char **tab);
void		search_player_pos(t_game *game, int i, int j);
void		find_next_wall(t_game *game);
void		draw_img(t_game *game, int r);
int			chose_texture(t_game *game, int ns, float angle);
uint32_t	get_text_img(t_game *game, int wHeight, double wallSize, float x);
float		next_point(t_game *game, float angle, char point);
float		*get_move(t_game *game, float col[2]);
void		collision(t_game *game, float col[2], float x, float y);
void		save(t_game *game);
char		*no_more_space(char *str);
char		*redef_line_bis(char *str);
int			check_nb_arg(char *str);
int			check_value(char *str);
char		*parse_strtocolor(char *str);
int			ft_isdigit(char *str);
int			good_value(char *line);
int			ft_isdigitnospace(char *str);
char		*no_more_space_bis(char *str);
char		*redef_jsp(char *str);
char		**map_fill_bis(char *av);
int			check_player(char **map);
char		*ft_one(int line_size);
char		*str_fill(char *str, char **map);
int			longest_line(char **map);
int			check_sign_map(char **map);

#endif