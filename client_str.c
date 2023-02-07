/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cllient_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:43:40 by tvillare          #+#    #+#             */
/*   Updated: 2023/01/23 18:57:56 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


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
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_usr;
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
	int	count;

	count = 0;
	ft_printf("%c", chr);
	while (8 > count)
	{
		usleep(300);
		if (chr & 128)
		{
			ft_printf("1");
			kill(pid, SIGUSR1);
		}
		else
		{
			ft_printf("0");
			kill(pid, SIGUSR2);
		}
		chr = chr & 127;
		chr = chr << 1;
		count++;
	}
	ft_printf("\n");
	return (1);
}

static void	put_len(int len, int pid)
{
	int		count;
	long	elevar;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_usr;

	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	elevar = 1;
	count = 0;
	while (31 > count)
	{
		usleep(300);
		if (len & elevar)
		{
			ft_printf("1");
			if (kill(pid, SIGUSR1) != 0)
				exit(1);
		}
		else
		{
			ft_printf("0");
			if (kill(pid, SIGUSR2) != 0)
				exit(1);
		}
		//len = chr & 127;
		//len = len >> 1;
		elevar *= 2;
		count++;
	}

}

/*
static void	ft_send_char(int pid_server, char letter)
{
	int		aux;
	int		k;

	k = 0;
	aux = letter;
	while (++k <= 8)
	{
		if (aux % 2 == 0)
		{
			usleep(300);
			if (kill(pid_server, SIGUSR2) == -1)
				exit(EXIT_FAILURE);
		}
		else
		{
			usleep(300);
			if (kill(pid_server, SIGUSR1) == -1)
				exit(EXIT_FAILURE);
		}
		aux >>= 1;
		//pause();
	}
}
static void	ft_send_str(int pid_server, char *str)
{
	int					i;
	struct sigaction	sa_confirm;

	i = -1;
	sa_confirm.sa_sigaction = &sig_usr;
	sigaction(SIGUSR2, &sa_confirm, NULL);
	while (str[++i])
		ft_send_char(pid_server, str[i]);
	i = -1;
	while (++i < 8)
	{
		usleep(100);
		if (kill(pid_server, SIGUSR2) == -1)
			exit(EXIT_FAILURE);
		//pause();
	}
}

*/

int	main(int argc, char **argv)
{
	int	pid;
	int	len;
	int	count;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_usr;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
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
	while (len > count)
		ft_killed(argv[2][count++], pid);
	//ft_send_str(pid, argv[2]);
	return (1);
}
