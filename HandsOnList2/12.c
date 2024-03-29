//Rittik Panda
//MT2022090
// Question : Write a program to create an orphan process. Use `kill` system call to send `SIGKILL` signal to the parent process from the child process.

#include <sys/types.h> // Import for `kill`, `fork`
#include <signal.h>    // Import for `kill`
#include <unistd.h>    // Import for `fork`, `sleep`
#include <stdio.h>     // Import for `perror` & `printf`

void main()
{
    pid_t childPid, parentPid;
    int killStatus; // Determines success of `kill`

    childPid = fork();

    if (childPid == -1)
        perror("Error while creating child!");
    else if (!childPid)
    {
        // Child will enter this branch
        printf("Child PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());

        sleep(5);

        kill(getppid(), SIGKILL);

        printf("Successfully killed parent!\n");
        sleep(5);
        printf("Parent id after killing (Should be orphan now): %d\n", getppid());
        printf("Child now exiting!\n");
       
    }
    else
    {
        // Parent will enter this branch
        while (1);
    }
}



