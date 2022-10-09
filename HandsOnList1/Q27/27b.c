#include<unistd.h>

int main()
{
	char *file_name = "ls";
	char *arg1 = "-Rl";
	
	execlp(file_name,file_name,arg1,NULL);
}
