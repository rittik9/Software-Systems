//Rittik Panda
//MT2022090
// Question : Write a separate program using signal system call to catch `SIGALRM` (use `setitimer` system call)

#include <sys/time.h> // Import `setitimer`
#include <signal.h>   // Import for `signal`
#include <unistd.h>   // Import for `_exit`
#include <stdio.h>    // Import `perror` & `printf`

void callback(int sig)
{
    printf("Signal SIGALRM has been caught with number %d\n", sig);
    _exit(0);
}

void main()
{
    int timerStatus;                  // Determines success of `setitimer` call
    __sighandler_t signalStatus; // Determines status of `signal` call

    struct itimerval timer;

    // Generate signal after 5s
    timer.it_value.tv_sec = 5;
    timer.it_value.tv_usec = 0;
    timer.it_interval.tv_sec = 0;
    timer.it_interval.tv_usec = 0;

    timerStatus = setitimer(ITIMER_REAL, &timer, 0);
    if (timerStatus == -1)
        perror("Error while setting an interval timer!");

    // Catch the SIGALRM signal
    signalStatus = signal(SIGALRM, (void *)callback);
    if (signalStatus == SIG_ERR)
        perror("Error while catching signal!");
    else
        while (1);
}
