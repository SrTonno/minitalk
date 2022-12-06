/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:45:14 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/06 11:48:43 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	ft_killed(char chr, int pid)
{
	int	count;
	int	out;

	count = 0;
	while (8 > count)
	{
		usleep(20);
		if (chr & 128)
		{
			out = kill(pid, SIGUSR1); //1
			//printf("1\n");
		}
		else
		{
			out = kill(pid, SIGUSR2); //0
			//printf("0\n");
		}
		//printf("%d->Salida%d\n", i, a);
		chr = chr & 127;
		chr = chr << 1;
		count++;
	}
	//printf("Fin%d\n", i);
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
	if (ft_isdigit(num) == 0)
	{
		ft_printf("Error: PID no valido");
		return (0);
	}
	num = atoi(argv[1]);
	count = 0;
	len = ft_strlen(argv[2]);
	//ft_printf("%s\n", argv[2]);
	while (len > count)
		ft_killed(argv[2][count++], num);
	return (0);
}
