/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:54:04 by romartin          #+#    #+#             */
/*   Updated: 2024/02/05 17:59:48 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_of_comma(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == ',')
			j++;
		i++;
	}
	if (j == 2)
		return (0);
	return (1);
}

int	all_clear(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	i++;
	while (str[i] && (str[i] < '0' && str[i] > '9'))
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	check_value(char *str)
{
	char	**ret;
	int		i;

	if (check_of_comma(str) == 1 || all_clear(str) == 1)
		return (1);
	ret = ft_split(str, ',');
	i = 0;
	if (tablen(ret) != 3)
	{
		free_tab(ret);
		return (1);
	}
	while (ret[i])
	{
		if (good_value(ret[i]) == 1)
		{
			free_tab(ret);
			return (1);
		}
		i++;
	}
	free_tab(ret);
	return (0);
}

int	check_nb_arg(char *str)
{
	char	**ret;

	ret = ft_split(str, ' ');
	if (tablen(ret) == 2)
	{
		free_tab(ret);
		return (0);
	}
	free_tab(ret);
	return (1);
}

char	*parse_strtocolor(char *str)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && (str[i] < '0' || str[i] > '9'))
		i++;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!ret)
		return (NULL);
	while (str[i])
	{
		ret[j] = str[i];
		i++;
		j++;
	}
	ret[j] = '\0';
	return (ret);
}
