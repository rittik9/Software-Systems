#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
int main()
{
    int fd;
    fd=open("4b.txt",O_CREAT|O_RDWR|O_EXCL,0777);
    if(fd == -1) 
    {
    printf("Can't create because file already exists,FD = -1 \n");
    }
    else
    {
    printf("File with file descriptor %d has been created & opened in read write mode \n",fd);
    }
    return 0;
}
