#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>     
#include <unistd.h>   
#include <stdio.h>    

void main(int len, char *arr[])
{
    char *filename;     
    int fd; 
    int stat;         

    if (len != 2)
        printf("Pass the file to be opened as the argument!\n");
    else
    {
        filename = arr[1];

        fd = open(filename, O_RDONLY);

        if (fd == -1)
            perror("Error while opening the file");
        else
        {
            stat = fcntl(fd, F_GETFL);

            if (stat == -1)
                perror("Error on executing fcntl!");
            else
            {
                switch (O_ACCMODE & stat)
                {
                case 0:
                    printf("The file has been opened with the flags : O_RDONLY\n");
                    break;
                case 1:
                    printf("The file has been opened with the flags : O_WRONLY\n");
                    break;
                case 2:
                    printf("The file has been opened with the flags : O_RDWR\n");
                    break;
                case 64:
                    printf("The file has been opened with the flags : O_CREAT\n");
                    break;
                case 512:
                    printf("The file has been opened with the flags : O_TRUNC\n");
                    break;
                case 1024:
                    printf("The file has been opened with the flags : O_APPEND\n");
                    break;
                case 577:
                    printf("The file has been opened with the flags : O_WRONLY | O_CREAT | O_TRUNC\n");
                    break;
                case 1089:
                    printf("The file has been opened with the flags : O_WRONLY | O_CREAT | O_APPEND\n");
                    break;
                case 578:
                    printf("The file has been opened with the flags : O_RDWR   | O_CREAT | O_TRUNC\n");
                    break;
                case 1090:
                    printf("The file has been opened with the flags : O_RDWR   | O_CREAT | O_APPEND\n");
                    break;
                default:
                    printf("Error!");
                }
            }
            close(fd);
        }
    }
}
