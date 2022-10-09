//Rittik Panda
//MT2022090
// Create a FIFO file using the "mkfifo" library function & "mknod" system call
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
void main()
{
    int statmf,statmn;
    //using "mkfifo" library function
    statmf = mkfifo("FIFO1",S_IRWXU);
    if(statmf==0)
    {
        printf("Successfully created fifo using mkfifo");
    }
    else
    {
        perror("Error while creating fifo");
    }
    //Using "mknod" system call
    statmn = mknod("FIFO2",__S_IFIFO | S_IRWXU,0);
    if(statmn==0)
    {
        printf("Successfully created fifo using mknod");
    }
    else
    {
        perror("Error while creating fifo");
    }
  } 
