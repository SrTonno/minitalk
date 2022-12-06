/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:18:19 by tvillare          #+#    #+#             */
/*   Updated: 2022/09/26 17:25:18 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	len;
	int	i;

	i = 0;
	if (!s)
		return ;
	if (!f)
		return ;
	len = ft_strlen(s);
	while (i < len)
	{
		f(i, s + i);
		i++;
	}
}
