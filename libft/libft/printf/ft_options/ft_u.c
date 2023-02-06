/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 19:04:12 by tvillare          #+#    #+#             */
/*   Updated: 2022/10/31 15:26:24 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_putnbr_un(unsigned int n, int count)
{
	char	tmp;

	count = 0;
	if (n > 9)
	{
		count += ft_putnbr_un(n / 10, count);
	}
	tmp = (n % 10) + '0';
	count += ft_putstr(tmp);
	return (count);
}

int	ft_u(va_list arg)
{
	unsigned int	num;
	int				count;

	num = va_arg(arg, unsigned int);
	count = ft_putnbr_un(num, 0);
	return (count);
}
