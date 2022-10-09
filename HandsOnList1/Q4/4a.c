#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
int main()
{
    int fd;
    fd=open("4a.txt",O_RDWR);
    if(fd == -1) 
    {
    perror("Error while opening the file");
    }
    else
    {
    printf("File with file descriptor %d opened in read write mode \n",fd);
    }
    return 0;
}
