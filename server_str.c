/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:43:38 by tvillare          #+#    #+#             */
/*   Updated: 2023/01/23 15:43:17 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

static void	viw_pid(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("pid: %d\n", pid);
}
//modificar para invertir guardar los datos
static void	sig_len(int signo, siginfo_t *info, void *context)
{
	static unsigned long long	elevar = 1;
	static int	i = 1;


	if (SIGUSR1 == signo)
	{
		g_data.len_str |= elevar;
		elevar *=2;
	}
	else if (SIGUSR2 == signo)
	{
		elevar *=2;
	}
	ft_printf("elevator->%d:%d->%d\n", i++, elevar, g_data.len_str);
	//if (kill(info->si_pid, SIGUSR1) == -1)
		//exit(EXIT_FAILURE);
	//if (elevar > 1073741824 ) //2^31
	if (32 <= i)
	{
		//ft_printf("aaaaaa");
		elevar = 1;
		i = 1;
		//g_data.len_str = 0;
	}
	//poner if fin de numero y setear el valor elebar en 1
}
static void	sig_usr(int signo, siginfo_t *info, void *context)
{
	static int	bit;
	static char	letter;
	static char	index;

	(void)context;
	if (signo == SIGUSR1)
	{
		//kill(info->si_pid, SIGUSR2);
		letter = letter << 1;
		letter |= 1;
		bit++;
	}
	else if (signo == SIGUSR2)
	{
		//kill(info->si_pid, SIGUSR2);
		bit++;
		letter = letter << 1;
	}
	if (8 <= bit)
	{
		bit = 0;
		g_data.str[index++] = letter;
		letter &= 0;
	}
}

static void	len_str(int bit)
{
	struct sigaction	sa;


	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sig_len;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("can not catch SIGUSR1\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("can not catch SIGUSR2\n");
	while (bit++ < 31)
	{
		ft_printf("%d\n", bit);
		pause();
	}
	ft_printf("//sig_len:%d\n", g_data.len_str);
	//bit = 0;
	//ft_calloc(sizeof(g_data.str), g_data.len_str);
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
	while (++i <= (g_data.len_str + 1) * 8)
	{
		pause();
	}
	ft_calloc(sizeof(g_data.str), g_data.len_str);
}

int	main(void)
{
	int	bit;

	bit = 0;
	viw_pid();
	while (1)
	{
		len_str(bit);
		//len_letter();
		ft_printf("--------------------");
		ft_printf("%s\n", g_data.str);
		g_data.len_str = 0;
		bit = 1;
		pause();
	}

	return (0);
}

