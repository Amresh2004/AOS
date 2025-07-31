#include<stdio.h>
#include<unistd.h>
#include<fcntl.h> //functional ctrl system call
#include<sys/types.h>
main()
{
	int fd;
	char lilbuf[20],bigbuf[1024];
	fd = open("Z:/home/amresh2004/a.txt",O_RDONLY);
	printf("File open");
	read(fd,lilbuf,20);
	read(fd,bigbuf,1024);
}






