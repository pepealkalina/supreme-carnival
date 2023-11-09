/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 10:34:51 by paescano          #+#    #+#             */
/*   Updated: 2023/11/09 14:15:35 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strndup(char *s, size_t x)
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

void	*ft_memcpy(void *dest, void *src, size_t n)
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (j + i + 1));
	if (!str)
		return (NULL);
	ft_memcpy(str, s1, i);
	ft_memcpy(str + i, s2, j);
	str[j + i] = '\0';
	free(s1);
	return (str);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
