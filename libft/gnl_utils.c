/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 17:53:22 by dgoubin           #+#    #+#             */
/*   Updated: 2023/08/19 14:09:17 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	gnl_strlen(char *str, int boolnl)
{
	int	cpt;

	cpt = 0;
	while (str[cpt])
	{
		if (boolnl && str[cpt] == '\n')
			return (cpt + 1);
		cpt++;
	}
	return (cpt);
}

char	*gnl_strcat(char *src, char *dest)
{
	char	*res;
	int		cpt;
	char	*tmp;

	if (!src || !dest)
	{
		free(dest);
		return (0);
	}
	res = (char *)malloc(sizeof(char)
			* (gnl_strlen(src, 0) + gnl_strlen(dest, 0) + 1));
	if (!res)
	{
		free(dest);
		return (0);
	}
	cpt = 0;
	tmp = dest;
	while (*tmp)
		res[cpt++] = *(tmp++);
	while (*src)
		res[cpt++] = *(src++);
	res[cpt] = 0;
	free(dest);
	return (res);
}

char	*gnl_strdup_untilnl(char *str, int boolnl)
{
	char	*res;
	int		cpt;

	if (!str)
		return (0);
	res = (char *)malloc(sizeof(char) * (gnl_strlen(str, boolnl) + 1));
	if (!res)
		return (0);
	cpt = 0;
	while (str[cpt])
	{
		res[cpt] = str[cpt];
		if (str[cpt++] == '\n' && boolnl)
			break ;
	}
	if (str[cpt - 1] == '\n')
		cpt--;
	res[cpt] = 0;
	return (res);
}