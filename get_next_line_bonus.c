/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:23:55 by aroullea          #+#    #+#             */
/*   Updated: 2024/11/08 16:46:32 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_add_line(char *remain)
{
	char	*new_line;
	char	*new_rem;
	size_t	size;
	size_t	i;

	i = 0;
	if ((remain == NULL) || (remain[0] == '\0'))
		return (NULL);
	size = ft_strlen(remain);
	new_line = ft_strchr(remain, '\n');
	if (new_line)
		size = ft_strlen(remain) - ft_strlen(new_line + 1);
	new_rem = (char *) malloc(sizeof(char) * (size + 2));
	if (new_rem == NULL)
		return (NULL);
	while (i < size)
	{
		new_rem[i] = remain[i];
		i++;
	}
	new_rem[i] = '\0';
	return (new_rem);
}

char	*ft_add_remain(char *remain)
{
	char	*new_rem;
	char	*end;
	size_t	size;

	if (remain == NULL || remain[0] == '\0')
		return (NULL);
	end = ft_strchr(remain, '\n');
	if (end)
		size = ft_strlen(end + 1);
	if (end && size)
	{
		new_rem = (char *) malloc(sizeof(char) * size + 1);
		if (new_rem == NULL)
			return (NULL);
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

char	*ft_read_line(int fd, char *buffer, char *remaining)
{
	char	*end;
	int		nb_read;

	end = NULL;
	nb_read = 1;
	while ((end == NULL) && (nb_read > 0))
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free(remaining);
			free(buffer);
			return (NULL);
		}
		buffer[nb_read] = '\0';
		if ((nb_read == 0) && (remaining == NULL))
			break ;
		remaining = ft_strjoin(remaining, buffer, ft_strlen(buffer));
		end = ft_strchr(buffer, '\n');
	}
	free(buffer);
	return (remaining);
}

char	*ft_add_buf(int fd, char *remaining)
{
	char	*buffer;

	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	remaining = ft_read_line(fd, buffer, remaining);
	return (remaining);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*remain[1024];

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	remain[fd] = ft_add_buf(fd, remain[fd]);
	if ((remain[fd] == NULL) || (remain[fd][0] == '\0'))
		return (NULL);
	line = ft_add_line(remain[fd]);
	remain[fd] = ft_add_remain(remain[fd]);
	return (line);
}

/*int   main(void)
{
    char    *str;
    int     fd;

    str = NULL;
    fd = open("test.txt", O_RDONLY);
   do
    {
        str = get_next_line(fd);
        if (str != NULL)
        {
            printf("%s", str);
            free (str);
        }
    } while (str != NULL);
    close(fd);
}*/
