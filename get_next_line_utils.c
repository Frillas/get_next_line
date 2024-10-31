/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 06:59:53 by aroullea          #+#    #+#             */
/*   Updated: 2024/10/31 16:08:27 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void ft_copy(char *destination, char *source, size_t n)
{
    size_t  i;

    i = 0;
    while (i < n)
    {
        *destination++ = *source++;
        i++;
    }
}

void    *ft_memmove(void *dest, const void *src, size_t n)
{
    size_t  i;
    char    *destination;
    char    *source;

    if (!dest && !src)
        return (NULL);
    destination = (char *)dest;
    source = (char *)src;
    i = 0;
    if (dest <= src)
    {
        ft_copy(destination, source, n);
    }
    else
    {
        source += (n -1);
        destination += (n -1);
        while (i < n)
        {
            *destination-- = *source--;
            i++;
        }
    }
    return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;
	char	letter;

	i = 0;
	letter = c;
	str = (char *)s;
	while (i < ft_strlen(str) + 1)
	{
		if (str[i] == letter)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*read_line(int fd, char *buffer, int *find)
{
	int			nb_read;
	char		*pos;
	
	pos = NULL;
	nb_read = read(fd, buffer, BUFFER_SIZE);
	if (nb_read <= 0)
		return (NULL);
	buffer[nb_read] = '\0';
	pos = ft_strchr(buffer, '\n');
	if (pos)
	{
		pos[1] = '\0';
		*find = 1;
	}	
	return (buffer);
}
