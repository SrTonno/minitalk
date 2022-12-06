/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 11:43:18 by tvillare          #+#    #+#             */
/*   Updated: 2022/09/19 16:58:12 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	x;

	i = 0;
	x = ft_strlen((char *)src);
	if (dstsize != 0)
	{
		while ((src[i] != '\0') && ((dstsize - 1) > i) && (dstsize != 0))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (x);
}
