/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 20:11:54 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/08 13:44:56 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(char const *str, ...);
int	ft_selectoption(char letter, va_list arg);
int	ft_c(va_list arg);
int	ft_di(va_list arg);
int	ft_u(va_list arg);
int	ft_s(va_list arg);
int	ft_x(unsigned int n, int count, char *base);
int	ft_p(va_list arg);
int	ft_putstr(char str);
int	ft_strchrp(const char *s, int c);

#endif
