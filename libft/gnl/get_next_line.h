/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:38:43 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/12 13:57:20 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
void	*update_buffer(char *buffer);
char	*ft_reader(char *buffer, int fd);
char	*ft_union(char *buffer, char *tmp);
size_t	ft_strlen_gnl(const char *s);
char	*get_next_line_bonus(int fd);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_strdup_gnl(char *s1);
void	*ft_calloc_gnl(size_t count, size_t size);
size_t	ft_strlcpy_gnl(char *dst, const char *src, size_t dstsize);
int		hunt_nl(char *tmp);

#endif
