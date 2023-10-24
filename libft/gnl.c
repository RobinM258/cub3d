/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:07:02 by dgoubin           #+#    #+#             */
/*   Updated: 2023/08/19 14:03:49 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_isnl(char *str)
{
	while (*str)
		if (*(str++) == '\n')
			return (1);
	return (0);
}

char	*gnl_get_line(char *buf, int fd)
{
	char	*res;
	int		r;

	res = NULL;
	if (buf[0])
		res = gnl_strdup_untilnl(&buf[0], 0);
	r = read(fd, buf, BUFFER_SIZE);
	buf[r] = '\0';
	while (r > 0)
	{
		if (!res)
			res = gnl_strdup_untilnl(&buf[0], 0);
		else
			res = gnl_strcat(&buf[0], res);
		if (!res)
			return (0);
		if (check_isnl(&buf[0]))
			return (res);
		r = read(fd, buf, BUFFER_SIZE);
		buf[r] = '\0';
	}
	if (r == -1)
		res = gnl_clearbuf(&buf[0], res);
	gnl_clearbuf(&buf[0], 0);
	return (res);
}

char	*gnl_clearbuf(char *str, char *res)
{
	while (*str)
		*(str++) = 0;
	if (res)
	{
		free(res);
		res = NULL;
	}
	return (res);
}

void	gnl_endingbuf(char *str)
{
	char	tmp[BUFFER_SIZE + 1];
	int		cpt;
	int		cpt2;

	cpt = 0;
	cpt2 = 0;
	while (str[cpt])
		tmp[cpt++] = str[cpt2++];
	tmp[cpt] = 0;
	cpt = 0;
	cpt2 = 0;
	while (tmp[cpt] && tmp[cpt++] != '\n')
		;
	while (tmp[cpt])
		str[cpt2++] = tmp[cpt++];
	while (cpt2 < BUFFER_SIZE + 1)
		str[cpt2++] = 0;
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	char		*res;
	char		*tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (check_isnl(&buf[0]))
		res = gnl_strdup_untilnl(&buf[0], 1);
	else
		res = gnl_get_line(&buf[0], fd);
	if (!res)
		return (0);
	tmp = gnl_strdup_untilnl(res, 1);
	free(res);
	if (!tmp)
		return (0);
	res = tmp;
	gnl_endingbuf(&buf[0]);
	return (res);
}