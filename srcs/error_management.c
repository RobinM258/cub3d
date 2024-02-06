/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:59:22 by romartin          #+#    #+#             */
/*   Updated: 2024/01/30 17:49:22 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error_walls(char *str, char *red, char *line)
{
	free(red);
	free(line);
	free(str);
	return (1);
}

int	error_parsing(char **map, char **map2, char *error)
{
	printf("%s\n", error);
	if (map2)
		free_tab(map2);
	if (map)
		free_tab(map);
	return (1);
}
