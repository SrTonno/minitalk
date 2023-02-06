/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 19:17:04 by tvillare          #+#    #+#             */
/*   Updated: 2022/10/08 20:14:00 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_putstr(char str)
{
	int	count;

	count = 0;
	if (!str)
		count = write(1, "(null)", 6);
	else
		count = write(1, &str, 1);
	return (count);
}
