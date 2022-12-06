/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:09:52 by tvillare          #+#    #+#             */
/*   Updated: 2022/10/02 16:28:37 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d;
	size_t	s;

	i = 0;
	if (dst == NULL && dstsize == 0)
		return (0);
	d = ft_strlen (dst);
	s = ft_strlen ((char *)src);
	if (dstsize <= d)
		return (dstsize + s);
	while (src[i] != '\0' && (d + i) < (dstsize - 1))
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	return (d + s);
}
