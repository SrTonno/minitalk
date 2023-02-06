/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_selectoption.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:37:27 by tvillare          #+#    #+#             */
/*   Updated: 2022/10/20 17:18:40 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
//cspdiuxX %
//  https://cplusplus.com/reference/cstdio/printf/

int	ft_selectoption(char letter, va_list arg)
{
	int	count;

	count = 0;
	if (letter == 'c')
		count += ft_c(arg);
	else if (letter == 's')
		count += ft_s(arg);
	else if (letter == 'p')
		count += ft_p(arg);
	else if (letter == 'd' || letter == 'i')
		count += ft_di(arg);
	else if (letter == 'u')
		count += ft_u(arg);
	else if (letter == 'X')
		count += ft_x(va_arg(arg, unsigned int), 0, "0123456789ABCDEF");
	else if (letter == 'x')
		count += ft_x(va_arg(arg, unsigned int), 0, "0123456789abcdef");
	else if (letter == '%')
		count += write(1, "%", 1);
	return (count);
}
