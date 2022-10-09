#include <unistd.h>   
#include <sys/types.h>
#include <sys/stat.h>  
#include <fcntl.h>    
#include <stdio.h>    

void main(int len, char *arr[])
{

    char *filename;               
    int fd, dfd; 
    int writeByteCount;                

    if (len != 2)
        printf("Enter the file name as argument\n");
    else
    {
        filename = arr[1];
        fd = open(filename, O_RDWR | O_APPEND);
        printf("%d",fd);
        
        if (fd == -1)
            perror("Error while opening file\n");
        else
        {
            dfd = fcntl(fd, F_DUPFD);
    

            // Writing using original file descriptor
            writeByteCount = write(fd, "Using original FD ", 17);
            if (writeByteCount == -1)
                perror("Error while writing file using original FD");

            // Writing using duplicate file descriptor
            writeByteCount = write(dfd, "Using duplicate FD", 18);
            if (writeByteCount == -1)
                perror("Error while writing file using duplicate FD");

            close(fd);
        }
    }
}
