#include <unistd.h>    
#include <sys/types.h>
#include <sys/stat.h>  
#include <fcntl.h>     

void main()
{
    char *filename = "22";
    int childPid, fileDescriptor;
    fileDescriptor = open(filename, O_CREAT | O_WRONLY | O_APPEND, S_IRWXU);

    if ((childPid = fork()) != 0) 
        write(fileDescriptor, "Parent\n!", 7);
    else 
        write(fileDescriptor, "Child\n!", 6);
    close(fileDescriptor);
}
