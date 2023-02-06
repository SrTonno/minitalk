/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 17:16:13 by tvillare          #+#    #+#             */
/*   Updated: 2022/09/28 17:19:53 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	hunt(const char *haystack, const char *needle, size_t i, size_t ln)
{
	int	p;

	p = 0;
	while (needle[p] != '\0' )
	{
		if (haystack[i] != needle[p])
			return (0);
		i++;
		p++;
	}
	if (ln < i)
		return (0);
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (haystack == NULL && len == 0)
		return (NULL);
	else if (needle[0] == '\0')
		return ((char *)haystack);
	while (i < len && haystack[i] != '\0')
	{
		if (haystack[i] == needle[0])
		{
			j = hunt(haystack, needle, i, len);
			if (j == 1)
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
