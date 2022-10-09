#include <sys/types.h> 
#include <unistd.h>    
#include <stdio.h>     

void main()
{
    pid_t childPid;

    if ((childPid = fork()) != 0)   //after fork parent will enter this
    {
        printf("Parent PID: %d\n", getpid());
        printf("Putting parent to sleep for 25s!\n");
        sleep(25);
        printf("Parent is now awake!\n");
    }
    else       //after fork child will enter this
    {
        printf("Child PID: %d\n", getpid());
        printf("Exiting child!\n");
        _exit(0); 
    }
}

