/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:40:23 by tvillare          #+#    #+#             */
/*   Updated: 2022/09/22 12:43:14 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		x1;
	int		x2;
	int		i;
	int		j;
	char	*pnt;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	x1 = ft_strlen((char *)s1);
	x2 = ft_strlen((char *)s2);
	i = 0;
	j = 0;
	pnt = malloc(sizeof(char) * (x1 + x2 + 1));
	if (pnt == NULL)
		return (NULL);
	while (s1[j] != '\0')
		pnt[i++] = (char)s1[j++];
	j = 0;
	while (s2[j] != '\0')
		pnt[i++] = (char)s2[j++];
	pnt[i] = '\0';
	return (pnt);
}
