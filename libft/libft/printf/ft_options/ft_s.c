/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 17:47:11 by tvillare          #+#    #+#             */
/*   Updated: 2022/10/29 20:40:49 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_s(va_list arg)
{
	char	*str;
	int		count;
	int		i;

	count = 0;
	i = 0;
	str = va_arg(arg, char *);
	if (!str)
	{
		count += write(1, "(null)", 6);
		return (count);
	}
	while (str[i] != '\0')
	{
		count += ft_putstr(str[i]);
		i++;
	}
	return (count);
}
