/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:43:38 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/15 16:53:11 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server_bonus.h"

t_data	g_data;

void	sig_len(int signo, siginfo_t *info, void *context)
{
	static long	elevar = 1;
	static int	i = 1;

	(void) context;
	if (SIGUSR1 == signo)
		g_data.len_str |= elevar;
	elevar *= 2;
	i++;
	if (32 == i)
	{
		elevar = 1;
		i = 1;
	}
	usleep(300);
	kill(info->si_pid, SIGUSR1);
}

static void	sig_usr(int signo, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static char	letter;
	static int	index = 0;

	(void)context;
	bit++;
	letter = letter << 1;
	if (signo == SIGUSR1)
		letter |= 1;
	if (bit == 8)
	{
		g_data.str[index++] = letter;
		bit = 0;
		if (index > g_data.len_str - 1)
			index = 0;
		letter = 0;
	}
	usleep(300);
	kill(info->si_pid, SIGUSR2);
}

static void	len_letter(void)
{
	struct sigaction	sa;
	int					i;

	i = 0;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_usr;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("can not catch SIGUSR1\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("can not catch SIGUSR2\n");
	while (++i <= (g_data.len_str) * 8)
		pause();
}

int	main(void)
{
	int	bit;

	g_data.len_str = 0;
	bit = 0;
	viw_pid();
	while (1)
	{
		len_str(bit);
		if (g_data.len_str != 0)
			g_data.str = ft_calloc(sizeof(char), g_data.len_str + 1);
		len_letter();
		g_data.len_str = 0;
		bit = 0;
		ft_printf("%s\n", g_data.str);
		if (g_data.str != NULL)
			free(g_data.str);
	}
	return (0);
}
