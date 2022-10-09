

#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

void main(){
	struct tkt_db{
		int tkno;
		int usrid;
	}db;
	
	int fd = open("ticket_db.txt", O_APPEND | O_RDWR);
	
	db.tkno = 3;
	db.usrid = 3;

	write(fd, &db, sizeof(db));	
	close(fd);
}
