/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:31:00 by aroullea          #+#    #+#             */
/*   Updated: 2024/10/31 11:38:59 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len_str;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
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
	char	*buf;
	char	*res;
	int		find;
	int		copy;

	find = 0;
	copy = 0;
	buf = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	if (buf == NULL)
		return (NULL);
	res = malloc(1);
	if (res == NULL)
		return (NULL);
	while (find == 0)
	{
		buf = read_line(fd, buf, &find);
		if (ft_strlen(buf) == BUFFER_SIZE)
		{
			res = ft_strjoin(res, buf);
			copy = 1;
		}
	}
	if (copy == 1)
	{
		res = ft_strjoin(res, buf);
		return (res);
	}
	return (buf);
}

int main(void)
{
	char	*str;
	int		fd;
	int		i;

	i = 0;
	str = NULL;
	fd = open("test.txt", O_RDONLY);
	str = get_next_line(fd);
	printf("%s",str);
	free(str);
	close(fd);
}
