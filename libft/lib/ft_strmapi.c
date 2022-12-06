/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:31:18 by tvillare          #+#    #+#             */
/*   Updated: 2022/09/28 13:11:05 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		i;
	char	*pnt;

	i = 0;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	if (len == 0)
		return (ft_calloc(1, sizeof(char)));
	pnt = ft_calloc(1, (len + 1));
	if (pnt == NULL)
		return (NULL);
	while (i < len)
	{
		pnt[i] = f(i, s[i]);
		i++;
	}
	return (pnt);
}
