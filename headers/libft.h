/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 16:38:06 by dgoubin           #+#    #+#             */
/*   Updated: 2024/02/02 18:47:29 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		check_isnl(char *str);
char	**find_map(char *av);
char	*get_next_line(int fd);
char	*ft_get_line(char *buf, int fd);
void	ft_endingbuf(char *str);
char	*ft_clearbuf(char *str, char *res);
char	*ft_substr(char *s, int start, int len);
char	*ft_strcat(char *src, char *dest);
char	*ft_strdup_untilnl(char *str, int boolnl);
int		tablen(char **str);
char	**map_fill(char *av);
int		line_map(char *str);
int		ft_strlen(char *str);
char	**ft_split(char *s, char c);
int		ft_atoi(char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
