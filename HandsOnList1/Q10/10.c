#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(void)
{
 int fd,x;
 fd=open("file.txt",O_CREAT|O_RDWR,0777);
 write(fd,"Rittik",6);
 x=lseek(fd,10,SEEK_CUR);
 write(fd,"Panda",5);
 close(fd);
 printf("%d",x);
}
