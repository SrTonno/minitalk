/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 16:39:07 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/15 16:50:09 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

void	viw_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("pid: %d\n", pid);
}

void	len_str(int bit)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &sig_len;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("can not catch SIGUSR1\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("can not catch SIGUSR2\n");
	while (bit++ < 31)
		pause();
}
