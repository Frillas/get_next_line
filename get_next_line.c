/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:31:00 by aroullea          #+#    #+#             */
/*   Updated: 2024/10/31 16:25:40 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *ft_strdup(const char *s)
{
    char        *dst;
    size_t      i;
    size_t      size;

    i = 0;
    size = ft_strlen(s);
    dst = (char *) malloc(size + 1);
    if (dst == NULL)
        return (NULL);
    while (i <= size)
    {
        dst[i] = s[i];
        i++;
    }
    return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len_str;
	char	*str;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	len_str = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(char) * (len_str + 1));
	if (str == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{ 
		str[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	char	*buf1;
	char	*res;
	int		find;
	int		i;

	res = NULL;
	find = 0;
	i = 1;
	buf1 = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	if (buf1 == NULL)
		return (NULL);
	while (find == 0)
	{
		buf1 = read_line(fd, buf1, &find);
		if (!find)
		{
			buf2 = ft_strdup(buf1);
			buf1 = (char *) malloc(sizeof(char) * BUFFER_SIZE * i);
			i++;
		}
	}
	return (buf1);
}

int main(void)
{
	char	*str;
	int		fd;

	str = NULL;
	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s",str);
	free(str);
	close(fd);
}
