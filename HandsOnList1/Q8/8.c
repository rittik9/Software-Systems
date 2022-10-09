#include<fcntl.h>
#include<stdio.h>
int main()
{
    char c;
    int fd;
    fd =open("q.txt", O_RDONLY);
    while(read(fd,&c,1))
    {
        if(c=="\n")
        {
            continue;
        }
        else
        printf("%c",c);
    }
    close(fd);
}
