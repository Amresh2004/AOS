// write a c program to that redirect standad output to a file output.txt (use of dup and open system call)
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int file=open("output.txt",O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if(file < 0)
	{
		perror("open");
		return 1;
	}
	int saved_output=dup(fileno(stdout));
	if(dup2(file,fileno(stdout))==-1)
	{
		perror("Error redirecting stanadrd output");
		close(file);
		return 1;
	}
	else
	{
		printf("this is redirected standrad output using dup and open system calls.\n");
		fflush(stdout);
		close(file);
		dup2(saved_output,fileno(stdout));
		close(saved_output);
		return 0;
	}
}




