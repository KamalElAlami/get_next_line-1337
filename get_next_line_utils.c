/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 15:04:45 by kael-ala          #+#    #+#             */
/*   Updated: 2023/12/17 17:14:14 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		len;
	char	*res;
	int		i;

	i = 0;
	len = ft_strlen(s1);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (*s1)
	{
		res[i] = *s1;
		s1++;
		i++;
	}
	res[i] = '\0';
	return (res);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (size)
	{
		while (src[i] && i < size - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srclen);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*constr;
	int		sl;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	sl = ft_strlen(s1) + ft_strlen(s2);
	constr = malloc(sizeof(char) * (sl + 1));
	if (!constr)
		return (NULL);
	ft_strlcpy(constr, s1, ft_strlen(s1) + 1);
	ft_strlcpy(constr + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free(s1);
	return (constr);
}

int	ft_strchr(char *s, int c)
{
	if (!s)
		return (1);
	while (*s)
	{
		if (*s == (char)c)
			return (0);
		s++;
	}
	return (1);
}
