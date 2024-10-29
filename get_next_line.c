/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 15:31:00 by aroullea          #+#    #+#             */
/*   Updated: 2024/10/29 11:32:31 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*dst;
	int		size;

	size = r_size(fd);
	printf("%d\n",size);
	dst = (char *) malloc(sizeof(char) * 5);
	if (dst == NULL)
		return (NULL);
	dst[0] = 'T';
	dst[1] = 'E';
	dst[2] = 'S';
	dst[3] = 'T';
	dst[4] = '\0';
	return (dst);
}

int main(void)
{
	char	*str;
	int		fd, nb_read;
	int		i;

	i = 0;
	str = NULL;
	nb_read = 1;
	fd = open("test.txt", O_RDONLY);
	while (i < 3)
	{
			str = get_next_line(fd);
			printf("%s\n",str);
			i++;
	}
	free(str);
	close(fd);
}
