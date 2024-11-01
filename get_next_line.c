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

char	*double_size(char *buf1, int i)
{
	char		*tmp;
	size_t		j;

	j = 0;
	tmp = NULL;
	tmp = (char *) malloc ((sizeof(char) * (BUFFER_SIZE * i)) + 1);
	if (tmp == NULL)
		return (NULL);
	while (j <= ft_strlen(buf1))
	{
		tmp[j] = buf1[j];
		j++;
	}
	free(buf1);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char	*buf1;
	char	*start_buf1;
	int		find;
	int		i;

	find = 0;
	i = 2;
	buf1 = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf1 == NULL)
		return (NULL);
	start_buf1 = buf1;
	while (find == 0)
	{
		buf1 = read_line(fd, buf1, &find);
		if (!find)
		{
			start_buf1 = double_size(start_buf1, i);
			buf1 = start_buf1;
			buf1 = ft_strchr(buf1, '\0');
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
	free (str);
	close(fd);
}
