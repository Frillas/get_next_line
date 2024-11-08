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
	if (remain[0] == '\0')
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
	char	*new;
	char	*end;
	size_t	size;
	size_t	i;

	i = 1;
	if (remain == NULL)
		return (NULL);
	end = ft_strchr(remain, '\n');
	if (end)
	{
		size = ft_strlen(end + 1);
		if (size > 0)
		{
			new = (char *) malloc(sizeof(char) * (size + 2));
			if (new == NULL)
				return (NULL);
			while (i <= size)
			{
				new[i - 1] = end[i];
				i++;
			}
			new[i - 1] = '\0';
			free(remain);
			return (new);
		}
		if (size == 0)
			free (remain);
	}
	if (!end)
		free(remain);
	return (NULL);
}

char	*ft_read_line(int fd, char *read_list)
{
	char	*buffer;
	char	*end;
	int		nb_read;

	end = NULL;
	nb_read = 1;
	buffer = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (NULL);
	while ((end == NULL) && (nb_read > 0))
	{
		nb_read = read(fd, buffer, BUFFER_SIZE);
		if (nb_read == -1)
		{
			free(read_list);
			free(buffer);
			return (NULL);
		}
		buffer[nb_read] = '\0';
		if ((nb_read == 0) && (read_list == NULL))
			break ;
		read_list = ft_strjoin(read_list, buffer);
		end = ft_strchr(buffer, '\n');
	}
	free(buffer);
	return (read_list);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*remain;

	line = NULL;
	remain = ft_read_line(fd, remain);
	if ((remain == NULL) || (ft_strlen(remain) == 0))
		return (NULL);
	line = ft_add_line(remain);
	remain = ft_add_remain(remain);
	return (line);
}

/*int   main(void)
{
    char    *str;
    int     fd;

    str = NULL;
    fd = open("read_error.txt", O_RDONLY);
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
