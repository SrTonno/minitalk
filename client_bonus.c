/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:45:14 by tvillare          #+#    #+#             */
/*   Updated: 2023/01/07 16:29:57 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"


static void	sig_usr(int signo)
{
	//printf("%d\n", bit);
	if (signo == SIGUSR1)
	{
		printf("✅\n");
	}
	if (signo == SIGUSR2)
	{
		printf("*");
	}
}

static int	ft_killed(char chr, int pid)
{
	int	count;
	int	out;
	int aux;

	aux = 1;
	count = 0;
	while (8 > count)
	{
		usleep(100); //20
		if (chr & 128 && aux == 1)
		{
			out = kill(pid, SIGUSR1); //1
			//printf("1\n");
		}
		else if (aux == 1)
		{
			out = kill(pid, SIGUSR2); //0
			//printf("0\n");
		}
		//printf("%d->Salida%d\n", i, a);
		aux = 0;
		if (signal(SIGUSR1, sig_usr) == SIG_ERR)
			ft_printf("can not catch SIGUSR1\n");
		if (signal(SIGUSR2, sig_usr) != SIG_ERR)
		{
			chr = chr & 127;
			chr = chr << 1;
			count++;
			aux = 1;
		}
		else
		{
			ft_printf("can not catch SIGUSR2\n");
		}
		if (out < 0)
			return (0);
	}
	//printf("Fin%d\n", i);
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
	//ft_printf("%s\n", argv[2]);
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
