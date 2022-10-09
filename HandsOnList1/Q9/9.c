#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
void main (){
	
	int fd = open("9", O_RDWR);

	if(fd==-1)
	{
		printf("Unable to open file\n");
		return;
	}
	struct stat filestat;
	if(fstat(fd, &filestat) <0 )
	{
		printf("Unable to get filestat\n");
		return;
	}

	printf("inode # : %ld\n", filestat.st_ino);
	printf("# of hardlinks : %ld\n", filestat.st_nlink);
	printf("User # : %ld\n", filestat.st_uid);
	printf("Group # : %ld\n", filestat.st_gid);
	printf("File size : %ld\n", filestat.st_size);
	printf("Block Size: %ld\n", filestat.st_blksize);
	printf("# of Blocks : %ld\n", filestat.st_blocks);
	printf("Time of Last Access : %ld\n", filestat.st_atim);
	printf("Time of Last Modification : %ld\n", filestat.st_mtim);
	printf("Time of Last Status Change : %ld\n", filestat.st_ctim);

	close(fd);

}


