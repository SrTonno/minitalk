/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 17:02:58 by tvillare          #+#    #+#             */
/*   Updated: 2022/10/29 20:40:57 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_put_longun(unsigned long long n, int count, char *base)
{
	if (n > 15)
		count = ft_put_longun(n / 16, count, base);
	count += ft_putstr(base[n % 16]);
	return (count);
}

int	ft_p(va_list arg)
{
	int					count;
	unsigned long long	value;

	count = write(1, "0x", 2);
	value = va_arg(arg, unsigned long long);
	count = ft_put_longun(value, count, "0123456789abcdef");
	return (count);
}
