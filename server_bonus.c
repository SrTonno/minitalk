/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:45:22 by tvillare          #+#    #+#             */
/*   Updated: 2022/12/06 18:52:52 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	viw_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("pid: %d\n", pid);
}

static int	max_num(signo)
{
	if (signo == SIGUSR1
		return (15);
	else if (signo == SIGUSR2)
		return (8);
}

static void	sig_usr(int signo)
{
	static int	bit;
	static char	letter;
	static int	pid;

	if
	pid = max_num(signo);
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
		bit = 0;
		ft_printf("%c", letter);
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

