#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
int main()
{
    int fd;
    fd=open("m.txt",O_CREAT|O_EXCL|O_RDWR);
    if(fd == -1) perror("err ");
    return 0;
}
