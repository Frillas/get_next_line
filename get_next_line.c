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

char	*double_size(char *s_buf, int i, size_t size)
{
	char		*new;
	size_t		j;

	j = 0;
	new = NULL;
	new = (char *) malloc ((sizeof(char) * (BUFFER_SIZE * i)) + size + 1);
	if (new == NULL)
		return (NULL);
	while (j <= ft_strlen(s_buf))
	{
		new[j] = s_buf[j];
		j++;
	}
	free(s_buf);
	return (new);
}

char	*get_next_line(int fd)
{
	char			*buf;
	char			*start_buf;
	int				find;
	int				i;
	static char		remain[BUFFER_SIZE];

	find = 0;
	i = 2;
	buf = (char *) malloc(sizeof(char) * (BUFFER_SIZE + ft_strlen(remain) + 1));
	if (buf == NULL)
		return (NULL);
	start_buf = buf;
	if (remain[0] != '\0')
	{
		ft_memmove(buf, remain, BUFFER_SIZE);
		buf = buf + ft_strlen(remain);
	}
	while (find == 0)
	{
		buf = read_line(fd, buf, &find, remain);
		if (buf == NULL)
		{
			free(start_buf);
			return (NULL);
		}
		if (!find)
		{
			start_buf = double_size(start_buf, i++, ft_strlen(remain));
			buf = ft_strchr(start_buf, '\0');
		}
	}
	return (start_buf);
}

int	main(void)
{
	char	*str;
	int		fd;

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
}
