/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_di.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 13:42:32 by tvillare          #+#    #+#             */
/*   Updated: 2022/10/31 15:26:35 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_putnbr(int n, int count)
{
	char	tmp;

	count = 0;
	if (n == -2147483648)
		count += write(1, "-2147483648", 11);
	else
	{
		if (0 > n)
		{
			n = n * -1;
			count += ft_putstr('-');
		}
		if (n > 9)
		{
			count += ft_putnbr(n / 10, count);
		}
		tmp = (n % 10) + '0';
		count += ft_putstr(tmp);
	}
	return (count);
}

int	ft_di(va_list arg)
{
	int	num;
	int	count;

	num = va_arg(arg, int);
	count = ft_putnbr(num, 0);
	return (count);
}
