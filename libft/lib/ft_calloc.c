/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:20:16 by tvillare          #+#    #+#             */
/*   Updated: 2022/09/26 14:56:58 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*pnt;
	size_t	len;

	len = size * count;
	if (len && len / size != count)
		return (NULL);
	pnt = malloc(len);
	if (pnt == NULL)
		return (pnt);
	ft_bzero(pnt, len);
	return (pnt);
}
