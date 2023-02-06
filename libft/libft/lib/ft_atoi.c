/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 17:04:06 by tvillare          #+#    #+#             */
/*   Updated: 2022/09/29 16:44:33 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	quitar_espacios(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	return (i);
}

static int	no_numero(const char *str, int i)
{
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	return (i);
}

static unsigned long	num_final(const char *str, int i, int z)
{
	unsigned long	num;
	unsigned long	sub;

	sub = 1;
	num = 0;
	z--;
	while (i <= z)
	{
		num = num + ((str[z] - '0') * sub);
		sub = sub * 10;
		z--;
	}
	return (num);
}

int	ft_atoi(const char *str)
{
	unsigned long	i;
	int				signo;
	unsigned long	final;

	i = quitar_espacios(str);
	signo = 0;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
				signo++;
	if (ft_isdigit(str[i]) == 0)
		return (0);
	if (str[i] < 48 || str[i] > 57)
		return (0);
	final = num_final(str, i, no_numero(str, i));
	if (final > LONG_MAX && signo == 0)
		return (-1);
	else if (final > LONG_MAX && signo == 1)
		return (0);
	if (signo == 1)
		return (-final);
	return (final);
}
