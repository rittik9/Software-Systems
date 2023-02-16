//Rittik Panda
//MT2022090
// Question : Write a program to print the maximum number of files can be opened within a process and size of a pipe (circular buffer).

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(){


    printf("Maximum number of files that can be opened: %ld\n",sysconf(_SC_OPEN_MAX));

    int fd = open("./myfifo",O_RDWR);
    printf("Max buffer size of Pipe: %ld\n",fpathconf(fd,_PC_PIPE_BUF));

}
