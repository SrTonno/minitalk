/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 13:30:16 by tvillare          #+#    #+#             */
/*   Updated: 2022/10/02 16:37:39 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	skip_start(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (ft_strchr((char *)set, s1[i]) == NULL)
			return (i);
		i++;
	}
	return (i);
}

static int	skip_end(char const *s1, char const *set)
{
	int	i;
	int	len;

	len = ft_strlen((char *)s1);
	i = len;
	while (i > 0)
	{
		if (ft_strchr((char *)set, s1[i]) == NULL)
		{
			if (len == i)
				return (i);
			else
				return (i + 1);
		}
		i--;
	}
	return (i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*pnt;
	int		i;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup((char *)s1));
	i = 0;
	start = skip_start(s1, set);
	end = skip_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	pnt = ft_calloc(1, (end - start + 1));
	if (pnt == NULL)
		return (pnt);
	ft_strlcpy(pnt, s1 + start, (end - start + 1));
	return (pnt);
}
