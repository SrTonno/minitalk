/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:43:38 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/13 17:09:49 by tvillare         ###   ########.fr       */
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

static void	sig_len(int signo, siginfo_t *info, void *context)
{
	static long	elevar = 1;
	static int	i = 1;
	//int			a;

	(void) context;
	//ft_printf("elevator->%d:%d->%d\n", i++, elevar, g_data.len_str);
	if (SIGUSR1 == signo)
		g_data.len_str |= elevar;
	elevar *= 2;
	i++;
	if (32 == i)
	{
		//ft_printf("\nFIN LEN\n");
		elevar = 1;
		i = 1;
		//g_data.len_str = 0;
	}
	usleep(200);
	kill(info->si_pid, SIGUSR1);
	/*if ((a = kill(info->si_pid, SIGUSR1)) != -1)
		ft_printf("|");
	else
		ft_printf("W");
	ft_printf("%d", a);*/
}

static void	sig_usr(int signo, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static char	letter;
	static int	index = 0;
	//int			a;

	(void)context;
	bit++;
	letter = letter << 1;
	if (signo == SIGUSR1)
	{
		//ft_printf("<1#%d>", bit);
		letter |= 1;
	}
	/*else if (signo == SIGUSR2)
	{
		ft_printf("<0#%d>", bit);
	}*/
	if (bit == 8)
	{
		//ft_printf("(%c/%d)\n", letter, bit);
		g_data.str[index++] = letter;
		bit = 0;
		if (index > g_data.len_str - 1)
		{
			index = 0;
			//ft_printf("\nFIN str\n");
		}
		letter = 0;
	}
	usleep(200);
	kill(info->si_pid, SIGUSR2);
	/*if ((a =) != -1)
		ft_printf("|");
	else
		ft_printf("()");
	ft_printf("%d", a);*/
}

static void	len_str(int bit)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &sig_len;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		ft_printf("can not catch SIGUSR1\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		ft_printf("can not catch SIGUSR2\n");
	while (bit++ < 31)
	{
		//ft_printf("/%d/\n", bit);
		pause();
	}
	//ft_printf("//sig_len:%d\n", g_data.len_str);
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
	{
		//ft_printf("&%d&", i%8);
		pause();
	}
}

int	main(void)
{
	int	bit;

	g_data.len_str = 0;
	bit = 0;
	viw_pid();
	while (1)
	{
		//ft_printf("\nStart\n");
		len_str(bit);
		//ft_printf("--------------------\n");
		if (g_data.len_str != 0)
			g_data.str = ft_calloc(sizeof(char), g_data.len_str + 1);
		len_letter();
		//ft_printf("\nFIN LEN\n");
		g_data.len_str = 0;
		bit = 0;
		ft_printf("%s\n", g_data.str);
		if (g_data.str != NULL)
			free(g_data.str);
		//ft_printf("\nFIN\n");
	}
	return (0);
}
