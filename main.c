#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int bytes_read;
    int fd;
    char buffer[1024];

    fd = open("test.txt", O_RDONLY);
    bytes_read = read(fd, buffer, 11);
    printf("%s", buffer);
}