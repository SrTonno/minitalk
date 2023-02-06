/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 13:14:52 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/08 13:45:07 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(char const *str, ...)
{
	va_list	arg;
	int		i;
	int		count;

	va_start(arg, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			if (ft_strchrp("cspdiuxX%", str[i + 1]) == 0)
				break ;
			count += ft_selectoption((char)str[++i], arg);
		}
		else
			count += write(1, &str[i], 1);
		if (str[i] != '\0')
			i++;
	}
	va_end(arg);
	return (count);
}
