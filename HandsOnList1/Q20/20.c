//Rittik Panda
//MT2022090
#include <unistd.h> 
#include <stdio.h>  
#include <stdlib.h> 

void main(int argc, char *argv[])
{
    int priority, newp;
    if (argc != 2)
        printf("Please pass the integer value to be added to the current nice value\n");
    else
    {   
        printf("%d",getpid());
        newp = atoi(argv[1]);
        priority = nice(0); 
        printf("Current priority: %d\n", priority);
        getchar();
        priority = nice(newp); 
        printf("New priority: %d\n", priority);
        getchar();
    }
}
