/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:13:25 by tvillare          #+#    #+#             */
/*   Updated: 2023/02/15 16:54:16 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H

# include <signal.h>
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/union_libft.h"

typedef struct s_data
{
	int		len_str;
	char	*str;
}				t_data;

void	viw_pid(void);
void	len_str(int bit);
void	sig_len(int signo, siginfo_t *info, void *context);

#endif
