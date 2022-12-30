/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:45:22 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/16 13:44:44 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	viw_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("pid: %d\n", pid);
}

static void	sig_usr(int signo)
{
	static int	bit;
	static char	letter;

	//printf("%d\n", bit);
	if (signo == SIGUSR1)
	{
		//printf("received SIGUSR1(1)\n");
		letter = letter << 1;
		letter |= 1;
		bit++;
	}
	else if (signo == SIGUSR2)
	{
		//printf("received SIGUSR2(0)\n");
		bit++;
		letter = letter << 1;
	}
	if (8 <= bit)
	{
		bit = 0;
		write(1, &letter, 1);
		//printf("\n---------------------\n\n");
		letter &= 0;
	}
}

int	main(void)
{
	viw_pid();
	if (signal(SIGUSR1, sig_usr) == SIG_ERR)
		ft_printf("can not catch SIGUSR1\n");
	if (signal(SIGUSR2, sig_usr) == SIG_ERR)
		ft_printf("can not catch SIGUSR2\n");
	while (1)
		pause();
	return (0);
}

