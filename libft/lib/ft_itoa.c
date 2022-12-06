/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 17:10:04 by tvillare          #+#    #+#             */
/*   Updated: 2022/10/02 17:59:19 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i++;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*putnum(char *pnt, int n, int neg, int count)
{
	if (n == 0)
		pnt[count] = '0';
	while (n > 0)
	{
		pnt[count--] = ((n % 10) + '0');
		n = n / 10;
	}
	if (neg == 1)
		pnt[count] = '-';
	return (pnt);
}

char	*ft_itoa(int n)
{
	int		count;
	char	*pnt;
	int		neg;

	neg = 0;
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		n = n * -1;
		neg++;
	}
	count = num_len(n) + neg;
	pnt = ft_calloc(1, (count-- + 1));
	if (pnt == NULL)
		return (NULL);
	pnt = putnum(pnt, n, neg, count);
	return (pnt);
}
