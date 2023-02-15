/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:43:40 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/15 15:53:27 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	sig_usr(int signo, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (signo == SIGUSR1)
		ft_printf("|");
	if (signo == SIGUSR2)
		ft_printf("*");
}

static int	valid_pid(char *str)
{
	int					count;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &sig_usr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	count = -1;
	while (str[++count] != 0)
		if (str[count] < 48 || str[count] > 57)
			return (1);
	return (0);
}

static int	ft_killed(char chr, int pid)
{
	int					count;
	struct sigaction	sa;
	int a;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &sig_usr;
	sigaction(SIGUSR2, &sa, NULL);
	count = 0;
	ft_printf("%c", chr);
	while (8 > count)
	{

		if (chr & 128)
		{
			//ft_printf("1");
			kill(pid, SIGUSR1);
		}
		else
		{
			//ft_printf("0");
			kill(pid, SIGUSR2);
		}
		pause();
		chr = chr & 127;
		chr = chr << 1;
		count++;
		a = 0;
		usleep(100);
		//while (pause() || a != 1000)
			//a++;

		//ft_printf("/%d/", a);
		//ft_printf("|");
	}
	//ft_printf("\n");
	return (1);
}

static void	put_len(int len, int pid)
{
	int					count;
	long				elevar;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &sig_usr;
	sigaction(SIGUSR1, &sa, NULL);
	elevar = 1;
	count = -1;
	while (31 > ++count)
	{
		if (len & elevar)
		{
			//ft_printf("1");
			if (kill(pid, SIGUSR1) == -1)
				exit(1);
		}
		else
		{
			//ft_printf("0");
			if (kill(pid, SIGUSR2) == -1)
				exit(1);
		}
		pause();
		elevar *= 2;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int					pid;
	int					len;
	int					count;

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
	ft_printf("%d/", len);
	put_len(len, pid);
	ft_printf("\n");
	usleep(50);
	while (len > count)
	{
		ft_killed(argv[2][count++], pid);
		//usleep(50);
	}
	return (1);
}
