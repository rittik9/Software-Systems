#include<stdio.h>

int main()
{
	char *bin_path = "/bin/ls";
	char *args[]={bin_path,"-Rl",NULL};
	execv(bin_path,args);
	return 0;
}
