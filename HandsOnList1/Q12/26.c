#include <unistd.h> 
void main()
{
    char *executable_path = "12.out";
    char *arg = "12";

    execl(executable_path, executable_path, arg, NULL);
}
