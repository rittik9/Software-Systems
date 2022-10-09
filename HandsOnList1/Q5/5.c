#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>

void main()
{
   char files[6];
   int c=1;
   while(1)
   {
     if(c<6)
     {
	sprintf(files, "file%d", c);   
	int fd = creat(files,O_RDWR|S_IRWXU);
	if(fd==-1) 
	{
	   perror("Error while creating the file");
	   return ;
	}
        c++;			
     }
  }	
}
