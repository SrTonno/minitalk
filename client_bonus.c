/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:45:14 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/06 18:34:12 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	signumorg(int num, int pid)
{
	int			count;
	int			out;

	out = kill(pid, SIGUSR1);
	while (15 > count)
	{
		usleep(20);
		if (num & 16384)
			out = kill(pid, SIGUSR1); //1
		else
			out = kill(pid, SIGUSR2); //0
		num = num & 16383;
		num = num << 1;
		count++;
		if (out < 0)
			return (0);
	}
}

static int	ft_killed(char chr, int pid)
{
	int			count;
	int			out;
	static	int type;

	count = 0;
	if (type == 0)
		signumorg(getpid(), pid);
	else
		out = kill(pid, SIGUSR2);
	type++;
	while (8 > count)
	{
		usleep(20);
		if (chr & 128)
			out = kill(pid, SIGUSR1); //1
		else
			out = kill(pid, SIGUSR2); //0
		chr = chr & 127;
		chr = chr << 1;
		count++;
		if (out < 0)
			return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	num;
	int	len;
	int	count;
	int	out;

	if (argc != 3)
	{
		ft_printf("Error: Numero de parametros erroneo");
		return (0);
	}
	/*if (ft_isdigit(num) == 1)
	{
		ft_printf("Error: PID no valido");
		return (0);
	}*/
	num = atoi(argv[1]);
	count = 0;
	len = ft_strlen(argv[2]);
	ft_printf("%s\n", argv[2]);
	while (len > count)
	{
		out = ft_killed(argv[2][count++], num);
		if (out < 0)
		{
			ft_printf("Error en la tranmision cliente servidor");
			return (0);
		}
	}
	return (1);
}
