//Rittik Panda
//MT2022090
// Question : Write two programs: first program is waiting to catch `SIGSTOP` signal, the second program will send the signal (using `kill` system call). Find out whether the first  program is able to catch the signal or not.

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void handler(int sig){
    printf("SIGSTOP has been caught with number: %d\n", sig);
    exit(0);
}

int main(){

    signal(SIGSTOP, handler);
    printf("Process Id: %d\n", getpid());
    printf("Waiting to catch SIGSTOP...\n");
    sleep(15);
    printf("Not able to catch.\n");      //SIGSTOP cannot be caught

    return 0;
}

/*
    A program cannot catch a SIGSTOP signal. We can conclude this by observing that the handler function is never executed and instead the program is terminated!
*/
