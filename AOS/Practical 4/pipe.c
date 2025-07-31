// Write a c program to implement a foloowing UNIX command(Use Fork,pipe and execlp)
#include<stdio.h>
#include<stdlib.h> // Use for standard lib
#include<unistd.h> // use for fork() system call
#include<sys/wait.h> // use for sleep or wait a system 
int main()
{
	int pipe_fd[2];
	pid_t child_pid;
	if(pipe(pipe_fd)==-1) // if -1 then its failed a process
	{
		perror("Error Creating pipe");
		exit(EXIT_FAILURE);
	}
	if((child_pid=fork())==-1) // if -1 then its failed a process
	{
		perror("Error creating child process");
		exit(EXIT_FAILURE);
	}
	if(child_pid==0) //if 0 then the process is true
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0],STDIN_FILENO); // Stanadrd Input is 1 means Write 
		close(pipe_fd[0]);
		execlp("wc","wc","-l",(char *)NULL); // execute command
		perror("Error Exceuting wc");
		exit("EXIT_FAULURE");
	}
	else
	{
		close(pipe_fd[0]);                                              dup2(pipe_fd[1],STDOUT_FILENO);                                 close(pipe_fd[1]);                                              execlp("ls","ls","-l",(char *)NULL);                            perror("Error Exceuting ls");                                   exit("EXIT_FAULURE");

	}
	wait(NULL);
	return 0;
}
