/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 16:56:22 by tvillare          #+#    #+#             */
/*   Updated: 2022/10/29 20:41:15 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_c(va_list arg)
{
	char	letter;
	int		count;

	letter = va_arg(arg, int);
	count = write(1, &letter, 1);
	return (count);
}
