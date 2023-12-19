/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:42:22 by kael-ala          #+#    #+#             */
/*   Updated: 2023/12/19 01:17:35 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_reader(int fd, char *rst)
{
	int		count;
	char	*buff;

	count = 1;
	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (ft_strchr(rst, '\n') != 0 && count > 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count < 0)
		{
			free(rst);
			return (free(buff), NULL);
		}
		buff[count] = '\0';
		rst = ft_strjoin(rst, buff);
	}
	free (buff);
	return (rst);
}

int	new_line_counter(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}

char	*line_stack(char *rst)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	if (!rst)
		return (NULL);
	j = new_line_counter(rst);
	buff = malloc(sizeof(char) * j + 1);
	if (!buff)
		return (free(rst), NULL);
	while (i < j)
	{
		buff[i] = rst[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

char	*rst_joiner(char *rst)
{
	int		i;
	int		j;
	char	*restofline;

	i = 0;
	j = 0;
	if (!rst || !*rst)
		return (free(rst), NULL);
	while (rst[i] && rst[i] != '\n')
		i++;
	restofline = malloc(sizeof(char) * (ft_strlen(rst) - i) + 1);
	if (rst[i] != '\0')
		i++;
	while (rst[i])
		restofline[j++] = rst[i++];
	restofline[j] = '\0';
	free(rst);
	return (restofline);
}

char	*get_next_line(int fd)
{
	char		*buff;
	static char	*rst[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	rst[fd] = ft_reader(fd, rst[fd]);
	if (!rst[fd] || !*(rst[fd]))
		return (free(rst[fd]), rst[fd] = NULL, NULL);
	buff = line_stack(rst[fd]);
	if (!buff)
		return (NULL);
	rst[fd] = rst_joiner(rst[fd]);
	return (buff);
}
