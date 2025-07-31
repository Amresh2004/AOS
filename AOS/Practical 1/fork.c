#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
	pid_t pid;
	printf("Before fork: This line is printed by the parent process.\n");
	pid=fork();
	if(pid < 0)
	{
		perror("fork failed");
		return 1;
	}
	else if(pid == 0)
	{
		printf("Child Process: My PID is %d, and my parent's PID is %d.\n",getpid(),getppid());
	}
	else
	{
		printf("Parent Process: My PID is %d, and my child's PID is %d.\n",getpid(),pid);
	}
	printf("After fork: This line is printed by both parent and child process.\n");
	return 0;
}

//printf("Before fork: this is printed bye the parent process.\n");
//print("beofe fork: this is printed by thr parent process.\n"
