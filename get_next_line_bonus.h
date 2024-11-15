/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:41:11 by aroullea          #+#    #+#             */
/*   Updated: 2024/11/15 15:15:14 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_big_line(int fd, char *buffer, char *rem);
char	*ft_size_buf(int fd, char *remaining);
char	*ft_add_line(char *line);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *s1, char const *s2, size_t k, size_t l);
size_t	ft_strlen(const char *s);
char	*ft_add_remain(char *remain);
char	*ft_copy(size_t size, char *new_rem, char *end);
char	*ft_small_line(int fd, char *rem, int nb);

#endif
