
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

void main(){
	struct tkt_db{
		int tkno;
		int usrid;
	}db, db2;
	int userid,retval;
	int fd = open("ticket_db.txt", O_RDWR);
	
	printf("Enter user ID to book Ticket : ");
	scanf("%d", &userid);

	struct flock lckdb = {F_WRLCK,SEEK_SET, 0, 0, getpid()};
	fcntl(fd, F_SETLK, &lckdb);
	

	while( read(fd, &db, sizeof(db)) );	//get db updated with the last record

	db2.tkno = db.tkno + 1; 
	db2.usrid = userid;

	
	if(write(fd, &db2, sizeof(db2))>0) //Writing Data
		printf("\nAlloted Ticket Number: %d\n", db2.tkno);
	
	perror("Status: ");
	
	lckdb.l_type = F_UNLCK; //to UNLOCK
	fcntl(fd, F_SETLK, &lckdb);


	close(fd);
}
