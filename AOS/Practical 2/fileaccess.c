// Write a c program to find whether a given file passed through command argument to check file exist or not

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char*argv[])
{
	if(argc !=2 )
	{
		fprintf(stderr,"Usage:%s <fname>\n",argv[0]);
		return 1;
	}
	const char *fname = argv[1];
	if(access(fname, F_OK) == 0)
	{
		printf("File '%s' exists in the current direactory.\n",fname);
	}
	else
	{
		printf("File '%s' does not exist in the current dieactory.\n",fname);
	}
	return 0;
}
