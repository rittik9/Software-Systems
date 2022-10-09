#include <sys/types.h> 
#include <unistd.h>    
#include <stdio.h>     

void main()
{
    pid_t childPid;

    if ((childPid = fork()) != 0)
    {
        printf("Parent PID: %d\n", getpid());
        printf("Putting Parent to sleep for 10s\n");
        sleep(10); 
        printf("Exiting parent!\n");
        _exit(0); 
    }
    else
    {
        printf("Child PID: %d\n", getpid());
        printf("Putting child to sleep for 20s!\n");
        sleep(20); 
        printf("Child is now awake!\n");
    }
}
