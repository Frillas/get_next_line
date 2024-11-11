/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aroullea <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:23:49 by aroullea          #+#    #+#             */
/*   Updated: 2024/11/08 16:47:31 by aroullea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	char	letter;
	size_t	i;

	i = 0;
	letter = c;
	str = (char *)s;
	while (i < ft_strlen(str) + 1)
	{
		if (str[i] == letter)
			return (&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char const *s2, size_t l)
{
	size_t	i;
	size_t	j;
	char	*str;
	size_t	k;

	i = 0;
	j = 0;
	k = ft_strlen(s1);
	str = malloc(sizeof(char) * (k + l + 1));
	if (str == NULL)
		return (NULL);
	while (i < k)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < l)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free (s1);
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL )
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_copy(size_t size, char *new_rem, char *end)
{
	size_t	i;

	i = 1;
	while (i <= size)
	{
		new_rem[i - 1] = end[i];
		i++;
	}
	new_rem[i - 1] = '\0';
	return (new_rem);
}
