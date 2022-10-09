#include <unistd.h> 
void main()
{
    char *executable_path = "7.out";
    char *arg = "7.c";

    execl(executable_path, executable_path, arg, NULL);
}
