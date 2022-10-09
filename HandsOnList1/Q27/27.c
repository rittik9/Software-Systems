#include <unistd.h> // Import for `execle` function
#include <stdio.h>  // Import for `printf` function

void main()
{
    char *command_path = "/bin/ls";
    char *options = "-Rl";
    char *file_arg = "/home/rittik24/Desktop/HandsOnList1"; // Set if you want to execute `ls` command on a particular file

    printf("============OUTPUT USING execle===============\n");
    execle(command_path, command_path, options, file_arg, NULL, NULL);
    printf("\n");
}
