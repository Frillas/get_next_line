/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:23:55 by aroullea          #+#    #+#             */
/*   Updated: 2024/11/13 19:03:24 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_add_line(char *rem)
{
	char	*new;
	size_t	size;
	size_t	i;

	size = 0;
	i = 0;
	if (!rem || !*rem)
		return (NULL);
	while (rem[size] && rem[size] != '\n')
		size++;
	new = (char *) malloc(sizeof(char) * (size + 1 + (rem[size] == '\n')));
	if (new == NULL)
		return (NULL);
	while (i < size + (rem[size] == '\n'))
	{
		new[i] = rem[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_add_remain(char *remain)
{
	char	*new_rem;
	char	*end;
	size_t	size;

	end = ft_strchr(remain, '\n');
	if (end)
		size = ft_strlen(end + 1);
	if (end && size)
	{
		new_rem = (char *) malloc(sizeof(char) * size + 1);
		if (new_rem == NULL)
		{
			free(remain);
			return (NULL);
		}
		ft_copy(size, new_rem, end);
		free(remain);
	}
	else
	{
		free (remain);
		return (NULL);
	}
	return (new_rem);
}

char	*ft_read_line(int fd, char *buffer, char *rem)
{
	char	*end;
	int		nb_read;

	end = NULL;
	nb_read = 1;
	while (end == NULL)
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free(rem);
			free(buffer);
			return (NULL);
		}
		buffer[nb_read] = '\0';
		if (nb_read == 0)
			break ;
		rem = ft_strjoin(rem, buffer, ft_strlen(rem), ft_strlen(buffer));
		if (rem == NULL)
			break ;
		end = ft_strchr(buffer, '\n');
	}
	free(buffer);
	return (rem);
}

char	*ft_add_buf(int fd, char *remaining)
{
	char	*buffer;

	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
	{
		if (remaining)
			free(remaining);
		return (NULL);
	}
	remaining = ft_read_line(fd, buffer, remaining);
	return (remaining);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*remain[1024];

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= 1024)
		return (NULL);
	remain[fd] = ft_add_buf(fd, remain[fd]);
	if ((remain[fd] == NULL) || (remain[fd][0] == '\0'))
		return (NULL);
	line = ft_add_line(remain[fd]);
	if (line == NULL)
	{
		free(remain[fd]);
		remain[fd] = NULL;
		return (NULL);
	}
	remain[fd] = ft_add_remain(remain[fd]);
	return (line);
}
