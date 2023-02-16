//Rittik Panda
//MT2022090
// Question : Write a separate program using sigaction system call to catch `SIGSEGV` signal

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void handler(int sig){
    printf("SIGSEGV has been caught with number: %d\n", sig);
    exit(1);
}

int main(){

    struct sigaction action;
    action.sa_handler = handler;
    action.sa_flags = 0;
    int i;
    sigaction(SIGSEGV, &action, NULL);
    printf("Enter a number: ");
    scanf("%d", i);
    return 0;
    return 0;
}
