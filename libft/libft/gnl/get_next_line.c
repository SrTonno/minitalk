/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvillare <tvillare@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 10:37:21 by tvillare          #+#    #+#             */
/*   Updated: 2022/11/24 17:00:29 by tvillare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*update_buffer(char *buffer)
{
	int		c_aux;
	int		count;
	char	*aux;

	count = 0;
	c_aux = 0;
	while (buffer[count] && buffer[count] != '\n')
		count++;
	if (!buffer[count])
	{
		free(buffer);
		return (NULL);
	}
	if (buffer[count] == '\n')
		count++;
	aux = ft_calloc_gnl((ft_strlen_gnl(buffer) - count) + 1, sizeof(char));
	if (!aux)
		return (NULL);
	while (buffer[count])
		aux[c_aux++] = buffer[count++];
	free(buffer);
	return (aux);
}

char	*ft_union(char *buffer, char *tmp)
{
	char	*aux;

	aux = ft_strjoin_gnl(buffer, tmp);
	if (!aux)
		return (NULL);
	free(buffer);
	return (aux);
}

int	hunt_nl(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_reader(char *buffer, int fd)
{
	char	*tmp;
	int		numbytes;

	if (buffer == NULL)
		buffer = ft_calloc_gnl(1, sizeof(char));
	numbytes = 1;
	tmp = ft_calloc_gnl((BUFFER_SIZE + 1), sizeof(char));
	if (tmp == NULL)
		return (NULL);
	while (0 < numbytes)
	{
		numbytes = read(fd, tmp, BUFFER_SIZE);
		if (numbytes == -1)
		{
			free(tmp);
			return (NULL);
		}
		tmp[numbytes] = '\0';
		buffer = ft_union(buffer, tmp);
		if (hunt_nl(tmp) > -1)
			break ;
	}
	free(tmp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*tmp;

	if (read(fd, 0, 0) < 0)
	{
		if (buffer != NULL)
		{
			free(buffer);
			buffer = NULL;
		}
		return (NULL);
	}
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffer = ft_reader(buffer, fd);
	if (!buffer)
		return (NULL);
	tmp = ft_strdup_gnl(buffer);
	buffer = update_buffer(buffer);
	return (tmp);
}
