/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:51:00 by romartin          #+#    #+#             */
/*   Updated: 2024/02/05 17:30:56 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*redef_line_bis(char *str)
{
	int		i;
	int		j;
	char	*ret;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '.')
		i++;
	while (str[i + j] && str[i + j] != ' ')
		j++;
	ret = malloc(sizeof(char) * j + 1);
	if (!ret)
		return (NULL);
	j = 0;
	while (str[i + j] && str[i + j] != ' ')
	{
		ret[j] = str[i + j];
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

char	*no_more_space(char *str)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i + j])
		j++;
	ret = malloc(sizeof(char) * j + 1);
	if (!ret)
		return (NULL);
	j = 0;
	while (str[i + j])
	{
		ret[j] = str[i + j];
		j++;
	}
	ret[j] = '\0';
	return (ret);
}

int	len_of_link(char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (line[i] == 'C' || line[i] == 'F')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i + j])
		j++;
	return (j);
}

char	*redef_jsp(char *str)
{
	int		i;
	int		j;
	char	*line;
	char	*ret;

	j = 0;
	i = 0;
	line = no_more_space(str);
	if (line[i] == 'C' || line[i] == 'F')
		i++;
	while (line[i] && line[i] == ' ')
		i++;
	j = len_of_link(str);
	ret = malloc(sizeof(char) * j + 1);
	if (!ret)
		return (NULL);
	j = 0;
	while (line[i + j])
	{
		ret[j] = line[i + j];
		j++;
	}
	ret[j] = '\0';
	free(line);
	return (ret);
}

char	*no_more_space_bis(char *str)
{
	int		i;
	int		j;
	int		k;
	char	*ret;

	i = 0;
	j = 0;
	k = 0;
	while (str[i] == ' ' && str[i])
		i++;
	k = i;
	while (str[j])
		j++;
	j--;
	while (j > 0 && str[j] && str[j] == ' ')
		j--;
	ret = malloc(sizeof(char) * (j - i) + 2);
	if (!ret)
		return (NULL);
	i = 0;
	while (k <= j)
		ret[i++] = str[k++];
	ret[i] = '\0';
	return (ret);
}
