//Rittik Panda
//MT2022090
// Question : Write a separate program using signal system call to catch `SIGALRM` (use `alarm` system call)

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<sys/time.h>

void handler(int sig){
    printf("SIGALRM has been caught with number: %d\n", sig);
}

int main(){

    signal(SIGALRM, handler);
    printf("Creating Alarm.\n");

    alarm(5);   //schedule alarm for 5 second.

    pause();    //Do not proceed until signal is handled.

    return 0;
}
