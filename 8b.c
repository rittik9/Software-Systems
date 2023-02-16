//Rittik Panda
//MT2022090
// Question : Write a separate program using signal system call to catch `SIGINT`


#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void handler(int sig){
    printf("\nSIGINT has been caught with number: %d\n", sig);
    exit(0);
}

int main(){

    signal(SIGINT, handler);
    printf("Waiting for Interrupt from keyboard.\n");
    sleep(10);
    printf("No SIGINT within 10 seconds\n");

    return 0;
}
