/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 07:02:31 by aroullea          #+#    #+#             */
/*   Updated: 2024/10/31 15:34:56 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#define	BUFFER_SIZE 5

char	*get_next_line(int fd);
char	*read_line(int fd, char *buffer, int *find);
size_t  ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_memmove(void *dest, const void *src, size_t n);

#endif
