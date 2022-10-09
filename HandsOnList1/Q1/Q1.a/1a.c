//Rittik Panda
//MT2022090
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(int len, char* arr[])
{
 
    int stat = symlink(arr[1], arr[2]);
    if(len!=3)
    {
        printf("Enter file path and symbolic link file path as arguments to the program");
    }
    
    if (stat == 0) 
    {
        printf("Soft link created succuessfuly");
    }
    else
    {
        perror("Error while creating the softlink");
    }
    return 0;
}
