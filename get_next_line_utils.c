/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 06:59:53 by aroullea          #+#    #+#             */
/*   Updated: 2024/10/29 12:02:36 by aroullea         ###   ########.fr       */
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
	return (0);
}

int	r_size(int fd, char *buffer)
{
	int			i;
	int			tot_read;
	int			nb_read;
	char		*dst_end;

	tot_read = 0;
	nb_read = BUFFER;
	dst_end = NULL;
	while ((nb_read == BUFFER) && !(dst_end))
	{
		nb_read = read(fd, buffer, BUFFER);
		if (nb_read == -1)
			return (0);
		i = nb_read;
		buffer[i] = '\0';
		dst_end = ft_strchr(buffer, '\n');
		if (dst_end)
			tot_read = (ft_strlen(buffer) - ft_strlen(dst_end)) + tot_read;
		else
			tot_read = nb_read + tot_read;
	}
	return (tot_read);
}
