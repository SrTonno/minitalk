/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:45:14 by tvillare          #+#    #+#             */
/*   Updated: 2023/01/22 13:05:55 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	sig_usr(int signo, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signo == SIGUSR1)
		printf("✅\n");
	if (signo == SIGUSR2)
		printf("*");
}

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
		usleep(300);
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
	int	pid;
	int	len;
	int	count;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_usr;
	if (argc != 3)
	{
		ft_printf("Error: Numero de parametros erroneo");
		return (0);
	}
	if (valid_pid(argv[1]) == 1)
	{
		ft_printf("Error: PID no valido");
		return (0);
	}
	pid = atoi(argv[1]);
	count = 0;
	len = ft_strlen(argv[2]);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (len > count)
		ft_killed(argv[2][count++], pid);
	return (1);
}
