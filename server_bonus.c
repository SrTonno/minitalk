/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:45:22 by tvillare          #+#    #+#             */
/*   Updated: 2023/01/18 14:55:01 by tvillare         ###   ########.fr       */
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
		letter = letter << 1;
		letter |= 1;
		bit++;
	}
	else if (signo == SIGUSR2)
	{
		bit++;
		letter = letter << 1;
	}
	if (8 <= bit)
	{
		kill(info->si_pid, SIGUSR1);
		bit = 0;
		write(1, &letter, 1);
		letter &= 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	viw_pid();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_usr;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("can not catch SIGUSR1\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("can not catch SIGUSR2\n");
	while (1)
		pause();
	return (0);
}
