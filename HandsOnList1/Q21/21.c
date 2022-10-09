//Rittik Panda
//MT2022090
#include <sys/types.h> 
#include <unistd.h>   
#include <stdio.h>     

void main()
{
    int childPid, pid;

    pid = getpid();

    printf("Parent PID: %d\n", pid);

    childPid = fork();

    if (childPid != 0) //parent will enter
        printf("Child PID: %d\n", childPid);
}
