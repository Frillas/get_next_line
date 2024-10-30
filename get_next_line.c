/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:31:00 by aroullea          #+#    #+#             */
/*   Updated: 2024/10/30 17:29:34 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;
	char	*pos;

	pos = NULL;
	buf = (char *) malloc(sizeof(char) * BUFFER_SIZE);
	if (buf == NULL)
		return (NULL);
	while (1)
	{
		buf = read_line(fd, buf);
		pos = ft_strchr(buf,'\n');
	}
	return (buf);
}

int main(void)
{
	char	*str;
	int		fd;

	str = NULL;
	fd = open("test.txt", O_RDONLY);
	do
	{
		str = get_next_line(fd);
		free(str);
	} while(str != NULL);
	close(fd);
}
