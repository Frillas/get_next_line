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

/*char	*ft_strjoin(char const *s1, char const *s2)
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
}*/

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

char    *ft_strcpy(char *dest, char *src)
{
    int i;

    i = 0;
    while (src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

void double_size(char *buf1, int i)
{
	char *tmp;

	tmp = NULL;
	tmp = (char *) malloc (sizeof(char *) * (BUFFER_SIZE * i));
	free(buf1);
	buf1 = tmp;
}

char	*get_next_line(int fd)
{
	char	*buf1;
	char	*buf2;
	char	*start_buf1;
	int		find;
	int		i;

	find = 0;
	i = 2;
	buf1 = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	if (buf1 == NULL)
		return (NULL);
	start_buf1 = buf1;
	while (find == 0)
	{
		buf1 = read_line(fd, buf1, &find);
		if (!find)
		{
			buf2 = ft_strdup(start_buf1);
			double_size(start_buf1, i);
			ft_strcpy(start_buf1,buf2);
			buf1 = ft_strchr(buf1, '\0');
			free(buf2);
			i++;
		}
	}
	return (start_buf1);
}

int main(void)
{
	char	*str;
	int		fd;

	str = NULL;
	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s",str);
	close(fd);
}
