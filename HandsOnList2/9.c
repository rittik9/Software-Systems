//Rittik Panda
//MT2022090
// Question : Write a program to ignore a `SIGINT` signal then reset the default action of the `SIGINT` signal - Use `signal` system call.

#include<stdio.h>
#include<signal.h>
#include <unistd.h>

int main(){
    signal(SIGINT, SIG_IGN);
    printf("Ignoring the SIGINT Signal...\n");
    printf("Press \"Ctrl + C\" to test\n");
    sleep(5);

    signal(SIGINT, SIG_DFL);
    printf("\n\nResetting to default action for SIGINT.\n");
    printf("Press \"Ctrl + C\" to test\n");
    sleep(5);
    printf("No SIGINT within 5 seconds.\n");
    return 0;
}
