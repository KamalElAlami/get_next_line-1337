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
    while(*str != "\n")
        i++;
    return (i);
}

char line_stack(char *rst, char buff)
{
    
}

char *get_next_line(int fd)
{
    char *buff;
    static char *rst;
    int count = 0;

    if (fd < 0 || BUFFER_SIZE < 0)
        return (NULL);
  
    rst =  ft_reader(fd, rst);
    
}


#include <fcntl.h>
#include <limits.h>
int main(void)
{
    int fd;
    fd  = open("ult.txt", O_RDONLY);
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
    printf("%s\n", get_next_line(fd));
}