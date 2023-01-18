/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:39:37 by tvillare          #+#    #+#             */
/*   Updated: 2023/01/18 15:01:46 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	valid_pid(char *str)
{
	int	count;

	count = -1;
	while (str[++count] != 0)
		if (str[count] < 48 || str[count] > 57)
			return (1);
	return (0);
}

static int	ft_killed(char chr, int pid)
{
	int	count;

	count = 0;
	while (8 > count)
	{
		usleep(100);
		if (chr & 128)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		chr = chr & 127;
		chr = chr << 1;
		count++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	num;
	int	len;
	int	count;

	if (argc != 3)
	{
		ft_printf("Error: Numero de parametros erroneo");
		return (0);
	}
	if (valid_pid(argv[1]) == 1)
	{
		ft_printf("Error: PID no valido");
		return (1);
	}
	num = atoi(argv[1]);
	count = 0;
	len = ft_strlen(argv[2]);
	while (len > count)
		ft_killed(argv[2][count++], num);
	return (1);
}
