/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kael-ala <kael-ala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:42:22 by kael-ala          #+#    #+#             */
/*   Updated: 2023/12/16 00:04:17 by kael-ala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char * ft_reader(int fd , char *rst)
{
    int count;
    char *buff;
    count = 0;
    
    buff = malloc(BUFFER_SIZE + 1);
    while(!(ft_strchr(rst, '\n')))
    {
        count = read(fd, buff, BUFFER_SIZE);
        if (count ==0)
        {
            free(buff);
            break;
        }
        rst = ft_strjoin(rst , buff);
    }
    return rst;
}

int new_line_counter(char *str)
{
    int i;

    i = 0;
    while(str[i] != '\n' || str[i] != '\0')
        i++;
    return (i);
}

char *line_stack(char *rst, char *buff)
{
    int i;
    int j;

    i = 0;
    j = new_line_counter(rst);
    buff = malloc(sizeof(char) * j + 1);
    while (i <= j)
    {
        buff[i] == rst[i];
        i++; 
    }
    buff[i] = '\0';
    return (buff);
}

char *rst_joiner(char *rst)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (rst[i] != '\n' || rst[i] != '\0')
        i++;
    if (rst[i] == '\n')
        i++;
    while (rst[i])
        rst[j++] = rst[i++];
    return (rst);
}

char *get_next_line(int fd)
{
    char *buff;
    static char *rst;
    int count = 0;

    if (fd < 0 || BUFFER_SIZE < 0)
        return (NULL);
  
    rst =  ft_reader(fd, rst);
    buff = line_stack(rst, buff);
    rst = rst_joiner(rst);
    
}


#include <fcntl.h>
#include <limits.h>
int main(void)
{
    // int fd;
    // fd  = open("ult.txt", O_RDONLY);
    // printf("%s\n", get_next_line(fd));
    // printf("%s\n", get_next_line(fd));
    // printf("%s\n", get_next_line(fd));
    // printf("%s\n", get_next_line(fd));
    char *rss = ft_strdup("kamal\nbobo");
    rst_joiner(rss);
    printf("%s", rss);
}