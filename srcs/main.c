/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 19:14:06 by dgoubin           #+#    #+#             */
/*   Updated: 2024/02/05 18:01:11 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int ac, char *av[])
{
	t_game	game;

	game.ray.savedist = 0;
	if (ac != 2)
	{
		printf("required: ./cub3d \"path_to_map\"\n");
		return (1);
	}
	if (parsing(av[1], &game))
		exit(1);
	init_game(&game, av[1]);
	init_window(&game);
	return (0);
}
