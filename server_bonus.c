/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:45:22 by tvillare          #+#    #+#             */
/*   Updated: 2023/01/07 16:25:15 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	viw_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("pid: %d\n", pid);
}

static void	sig_usr(int signo, siginfo_t *info, void *context)
{
	static int	bit;
	static char	letter;

	(void)context;
	if (signo == SIGUSR1)
	{
		//printf("received SIGUSR1(1)\n");
		//ft_printf("client-pid: %d\n", info->si_pid);
		ft_printf("%d", bit);
		letter = letter << 1;
		letter |= 1;
		bit++;
		kill(info->si_pid, SIGUSR2);
	}
	else if (signo == SIGUSR2)
	{
		ft_printf("%d", bit);
		//ft_printf("client-pid: %d\n", info->si_pid);
		bit++;
		letter = letter << 1;
		kill(info->si_pid, SIGUSR2);
	}
	if (8 <= bit)
	{
		bit = 0;
		write(1, &letter, 1);
		write(1, "\n", 1);
		//printf("\n---------------------\n\n");
		letter &= 0;
		kill(info->si_pid, SIGUSR1);
	}
}

int	main(void)
{
	struct sigaction	sa;

	viw_pid();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_usr;
	//sigaction(SIGUSR1, &sa, NULL);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("can not catch SIGUSR1\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("can not catch SIGUSR2\n");
	while (1)
		pause();
	return (0);
}

