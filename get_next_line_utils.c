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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	if (dest <= src)
	{
		while (i < n)
		{
			*(char *)dest++ = *(char *)src++;
			i++;
		}
	}
	else
	{
		src += (n -1);
		dest += (n -1);
		while (i < n)
		{
			*(char *)dest-- = *(char *)src--;
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
	char	*str;
	char	letter;
	size_t	i;

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

char	*read_line(int fd, char *buffer, int *find, char *remaining)
{
	int		nb_read;
	char	*end;
	size_t	i;

	i = 1;
	end = NULL;
	nb_read = read(fd, buffer, BUFFER_SIZE);
	if (nb_read <= 0)
		return (NULL);
	buffer[nb_read] = '\0';
	end = ft_strchr(buffer, '\n');
	if (end)
	{
		while (i <= ft_strlen(end + 1))
		{
			remaining[i - 1] = end[i];
			i++;
		}
		remaining[i - 1] = '\0';
		end[1] = '\0';
		*find = 1;
	}
	return (buffer);
}
