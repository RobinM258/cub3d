/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: robin <robin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:44:16 by dgoubin           #+#    #+#             */
/*   Updated: 2023/10/10 12:54:35 by robin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define BUFFER_SIZE 50

void    ft_freetab(char **tab);
int     ft_strlen(char *str);
void    ft_printab(char **tab);
char    *ft_itoa(int n);
char    *ft_strjoin(char *s1, char *s2);

/*               GNL                 */
char	*get_next_line(int fd);
void	gnl_endingbuf(char *str);
char	*gnl_clearbuf(char *str, char *res);
char	*gnl_get_line(char *buf, int fd);
int	    check_isnl(char *str);

char	*gnl_strdup_untilnl(char *str, int boolnl);
char	*gnl_strcat(char *src, char *dest);
int	    gnl_strlen(char *str, int boolnl);

#endif