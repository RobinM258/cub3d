/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:44:32 by romartin          #+#    #+#             */
/*   Updated: 2024/02/05 17:53:03 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *b, int n)
{
	char	*str;
	int		i;

	str = b;
	i = 0;
	while (i < n)
	{
		*str = 0;
		str++;
		i++;
	}
}

void	*ft_calloc(int count, int size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, size * count);
	return (ptr);
}

char	*ft_substr(char *s, int start, int len)
{
	int		i;
	char	*str;
	int		x;

	i = start;
	x = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_calloc(1, 1));
	if (len > ft_strlen(s) && ft_strlen(s) != 0)
		len = ft_strlen(s) - start;
	else if (ft_strlen(s) - start <= len)
		len = ft_strlen(s) - start;
	else if (ft_strlen(s) > start && len < start)
		len = len + 1 - 1;
	else if (len < start)
		len = start - len;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < (len + start) && s[i])
		str[x++] = s[i++];
	str[x] = 0;
	return (str);
}
