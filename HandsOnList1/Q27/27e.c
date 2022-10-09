#include<stdio.h>

int main()
{
	char *bin_path = "ls";
	char *args[]={bin_path,"-Rl",NULL};
	execvp(bin_path,args);
	return 0;
}
