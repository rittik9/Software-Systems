//Rittik Panda
//MT2022090
// Question : Write a separate program using signal system call to catch `SIGSEGV`

#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void handler(int sig){
    printf("SIGSEGV has been caught with number:%d \n",sig);
    exit(0);
}

int main(){

    int i;
    signal(SIGSEGV, handler);
    printf("Creating segmentation fault...\n");
    printf("Enter a number: ");
    scanf("%d", i);
    return 0;
}
