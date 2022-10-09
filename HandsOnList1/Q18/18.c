#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>

void main(){
	struct tkt_db{
		int tkno;
		int usrid;
	}db, db2;
	int userid,	 retval;
	
	int fd = open("ticket_db.txt", O_RDWR);
	
	printf("Enter user ID to book Ticket : ");
	scanf("%d", &userid);

	
	struct flock lckdb;
		lckdb.l_type = F_RDLCK;
		lckdb.l_whence = SEEK_END; //from end
		lckdb.l_start = -sizeof(db); // go 1 record back
		lckdb.l_len = sizeof(db);
		lckdb.l_pid = getpid();

	fcntl(fd, F_SETLK, &lckdb);
	

	while( read(fd, &db, sizeof(db)) );	//get db updated with the last record

	db2.tkno = db.tkno + 1; 
	db2.usrid = userid;
	
	lckdb.l_type = F_UNLCK; //to UNLOCK the last record
	fcntl(fd, F_SETLK, &lckdb);

	lckdb.l_type = F_WRLCK;
	lckdb.l_whence = SEEK_END; //from end
	lckdb.l_start = 0; 
	lckdb.l_len = sizeof(db);
	lckdb.l_pid = getpid();

	fcntl(fd, F_SETLK, &lckdb);


	if(write(fd, &db2, sizeof(db2))>0) //Writing Data
		printf("\nAlloted Ticket Number: %d\n", db2.tkno);
	getchar();
	
	lckdb.l_type = F_UNLCK; //to UNLOCK the lst record
	fcntl(fd, F_SETLK, &lckdb);

	perror("Status: ");
	

	close(fd);
}
