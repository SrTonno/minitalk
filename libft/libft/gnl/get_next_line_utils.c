/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:21:59 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/08 17:26:55 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	*ft_calloc_gnl(size_t count, size_t size)
{
	void	*ptn;
	size_t	len;
	size_t	i;

	i = 0;
	len = size * count;
	if (len && len / size != count)
		return (NULL);
	ptn = malloc(len);
	if (ptn == NULL)
		return (ptn);
	while (len > i)
		((char *)ptn)[i++] = '\0';
	return (ptn);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	int		x1;
	int		x2;
	int		i;
	int		j;
	char	*pnt;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	x1 = ft_strlen_gnl((char *)s1);
	x2 = ft_strlen_gnl((char *)s2);
	i = -1;
	j = 0;
	pnt = ft_calloc_gnl(sizeof(char), (x1 + x2 + 1));
	if (pnt == NULL)
		return (NULL);
	while (s1[++i] != '\0')
		pnt[i] = (char)s1[i];
	while (s2[j] != '\0')
		pnt[i++] = (char)s2[j++];
	pnt[i] = '\0';
	return (pnt);
}

char	*ft_strdup_gnl(char *s1)
{
	int		count;
	char	*s2;

	count = 0;
	if (!s1[count])
		return (NULL);
	while (s1[count] && s1[count] != '\n')
		count++;
	if (s1[count] == '\n')
		count++;
	s2 = NULL;
	s2 = ft_calloc_gnl(sizeof(char), (count + 2));
	if (NULL == s2)
		return (NULL);
	count = 0;
	while (s1[count] && s1[count] != '\n')
	{
		s2[count] = s1[count];
		count++;
	}
	if (s1[count] && s1[count] == '\n')
		s2[count++] = '\n';
	s2[count] = '\0';
	return (s2);
}
