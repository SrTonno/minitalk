/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 18:38:34 by tvillare          #+#    #+#             */
/*   Updated: 2022/09/29 16:37:58 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*pnt;
	size_t	i;
	size_t	count;

	i = 0;
	if (!s)
		return (NULL);
	count = ft_strlen(s);
	if (start >= count)
		len = 0;
	if ((count - start) < len)
		len = count - start;
	pnt = ft_calloc((len + 1), sizeof(*s));
	if (!pnt)
		return (NULL);
	while (len > i)
		pnt[i++] = (char)s[start++];
	return (pnt);
}
