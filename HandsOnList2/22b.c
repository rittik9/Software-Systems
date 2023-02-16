//Rittik Panda
//MT2022090
// Question : Write a program to wait for data to be written into FIFO within 10 seconds, use `select` system call with FIFO.

#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>
#include<sys/time.h>
#include<string.h>
extern int errno;

int main(int argc, char * argv[]){
  int fd = open("./myfifo",O_RDONLY);
  int timeout=10;                   //TimeOut For 10 seconds
  struct timeval tv;
  tv.tv_sec = timeout;
  tv.tv_usec=0;
  fd_set readfds;
  FD_ZERO(&readfds);
  FD_SET(fd,&readfds);   //adding fd of myfifo to set of readfds
  int ret = select(fd+1,&readfds,NULL,NULL,&tv);  //select monitors multiple fds ,until they beome ready for io


  if (ret==-1)
  {
	perror("Error occured in select\n");
	printf("%d\n",errno);

  }
  else if (ret==0){
	printf("No Data within %d seconds\n",timeout);

  }
  else{
		char buf[100];
		int len = sizeof(buf)-1;
		int read_ret;
		read_ret=read(fd,buf,len);
		if(read_ret==-1)
			perror("read");
		else
			write(STDOUT_FILENO,buf,strlen(buf));
  }
  return 0;	
}
