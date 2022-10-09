#include<stdio.h>
#include<fcntl.h>
void main()
{
    int fd=creat("3.txt",S_IRWXU);
    if(fd==-1)
    {
    perror("Error while creating the file");
    }
    else
    {
    printf("The file is created successfully with the file descriptor %d \n",fd);
    }
}
