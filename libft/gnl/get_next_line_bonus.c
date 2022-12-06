/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:37:21 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/12 15:01:11 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line_bonus(int fd)
{
	static char	*buffer[1024];
	char		*tmp;

	if (read(fd, 0, 0) < 0)
	{
		if (buffer[fd] != NULL)
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
		}
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer[fd] = ft_reader(buffer[fd], fd);
	if (!buffer[fd])
		return (NULL);
	tmp = ft_strdup_gnl(buffer[fd]);
	buffer[fd] = update_buffer(buffer[fd]);
	return (tmp);
}
