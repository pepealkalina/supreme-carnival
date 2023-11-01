/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 13:14:48 by paescano          #+#    #+#             */
/*   Updated: 2023/11/01 11:28:33 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr2(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen2(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strndup2(char *s, size_t x)
{
	size_t	i;
	char	*str;

	str = malloc(sizeof(char) * (x + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < x)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

void	*ft_memcpy2(void *dest, void *src, size_t n)
{
	char	*odest;
	char	*osrc;
	size_t	i;

	i = 0;
	odest = (char *)dest;
	osrc = (char *)src;
	if (!dest && !src)
		return (NULL);
	while (i < n)
	{
		*(odest + i) = *(osrc + i);
		i++;
	}
	return (dest);
}

char	*ft_strjoin2(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
		i = 0;
	else
		i = ft_strlen2(s1);
	if (s2 == NULL)
		j = 0;
	else
		j = ft_strlen2(s2);
	str = (char *)malloc(sizeof(char) * (j + i + 1));
	if (!str)
		return (NULL);
	ft_memcpy2(str, s1, i);
	ft_memcpy2(str + i, s2, j);
	str[j + i] = '\0';
	free(s1);
	return (str);
}

size_t	ft_strlen2(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
