/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:29:04 by tvillare          #+#    #+#             */
/*   Updated: 2022/10/02 16:36:52 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	*inverso(char *last_d, const char *last_s, size_t len)
{
	char	aux;

	while (len--)
	{
		aux = *last_s--;
		*last_d = aux;
		last_d--;
	}
	return (last_d);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	if (dst == NULL && src == NULL)
		return (dst);
	d = (char *)dst;
	s = (const char *)src;
	if (d < s)
	{
		while (len--)
			*d++ = *s++;
	}
	else
	{
		d = d + (len -1);
		s = s + (len - 1);
		inverso(d, s, len);
	}
	return (dst);
}
