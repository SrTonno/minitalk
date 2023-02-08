/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 15:43:38 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/08 19:05:36 by tvillare         ###   ########.fr       */
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
	static  long	elevar = 1;
	static int		i = 1;

	(void) info;
	(void) context;
	//ft_printf("elevator->%d:%d->%d\n", i++, elevar, g_data.len_str);
	if (SIGUSR1 == signo)
	{
		g_data.len_str |= elevar;
		kill(info->si_pid, SIGUSR1);
		//ft_printf("(1-%d-%d-%d)", g_data.len_str, elevar, i);
		elevar *=2;
		i++;

	}
	else if (SIGUSR2 == signo)
	{
		//ft_printf("(0-%d-%d-%i)", g_data.len_str, elevar, i);
		kill(info->si_pid, SIGUSR1);
		elevar *=2;
		i++;

	}

	//if (kill(info->si_pid, SIGUSR1) == -1)
		//exit(EXIT_FAILURE);
	//if (elevar > 1073741824 ) //2^31
	if (32 == i)
	{
		ft_printf("\nFIN LEN\n");
		elevar = 1;
		i = 1;
		//g_data.len_str = 0;
	}
}

static void	sig_usr(int signo, siginfo_t *info, void *context)
{
	static int	bit = 0;
	static char	letter;
	static int	index = 0;

	(void)context;
	(void) info;
	if (signo == SIGUSR1)
	{
		kill(info->si_pid, SIGUSR2);
		ft_printf("<1#%d>", bit);
		letter = letter << 1;
		letter |= 1;
		bit++;
	}
	else if (signo == SIGUSR2)
	{
		kill(info->si_pid, SIGUSR2);
		ft_printf("<0#%d>", bit);
		bit++;
		letter = letter << 1;
	}
	if (bit == 8)
	{
		ft_printf("(%c/%d)\n", letter, bit);
		//bit = 0;
		g_data.str[index++] = letter;
		bit = 0;
		if (index > g_data.len_str - 1)
		{
			index = 0;

			ft_printf("\nFIN str\n");
		}
		letter = 0;
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
		 ft_printf("/%d/\n", bit);
		pause();
	}
	ft_printf("//sig_len:%d\n", g_data.len_str);
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
	while (++i <= (g_data.len_str) * 8 || g_data.len_str == 0) //g_data.len_str
	{
		//ft_printf("&%d&", i%8);
		pause();
	}
}

/*
static void	ft_sig_handler_str(int sig, siginfo_t *info, void *ucontext)
{
	static int	i = 0;
	static int	j = -1;
	static int	c;

	(void)ucontext;
	if (sig == SIGUSR1)
	{
		c >>= 1;
		c += 128;
	}
	else
		c >>= 1;
	if (++i % 8 == 0)
	{
		g_data.str[++j] = (char)c;
		if ((char)c == '\0')
		{
			j = -1;
		}
	}
	usleep(100);
	//if (kill(info->si_pid, SIGUSR1) == -1)
		//exit(EXIT_FAILURE);
	return ;
}


static void	ft_receive_str()
{
	int					i;
	struct sigaction	sa_char;

	g_data.str = malloc(sizeof(char) * (g_data.len_str + 1));
	if (!g_data.str)
		exit(EXIT_FAILURE);
	sa_char.sa_flags = SA_SIGINFO;
	sa_char.sa_sigaction = &ft_sig_handler_str;
	sigaction(SIGUSR1, &sa_char, NULL);
	sigaction(SIGUSR2, &sa_char, NULL);
	i = 0;
	while (++i <= (g_data.len_str + 1) * 8)
	{
		pause();
	}
	return ;
}
*/

int	main(void)
{
	int	bit;

	g_data.len_str = 0;
	bit = 0;
	viw_pid();
	while (1)
	{
		ft_printf("\nStart\n");
		len_str(bit);
		//usleep(10);
		ft_printf("--------------------\n");
		ft_printf("%d\n", g_data.len_str);
		g_data.str = ft_calloc(sizeof(char), g_data.len_str + 1);
		len_letter();
		//ft_receive_str();
		g_data.len_str = 0;
		bit = 0;
		ft_printf("\n%s/a/\n", g_data.str);
		if (g_data.str != NULL)
			free(g_data.str);
		ft_printf("\nFIN\n");
		//pause();
	}

	return (0);
}

