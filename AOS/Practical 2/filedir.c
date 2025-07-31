// Write a c program to read the current dir and display the name of files no of files in current dir.

#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
int main()
{
	DIR *dir;
	struct dirent *entry;
	int fCount=0;
	dir = opendir(".");
	if(dir == NULL)
	{
		perror("opendir");
		return 1;
	}
	printf("Files in the curret direactory:\n");
	while((entry = readdir(dir))!=NULL)
	{
		if(entry->d_type == DT_REG)
		{
			printf("%s\n",entry->d_name);
			fCount++;
		}
	}
	closedir(dir);
	printf("Number of files in thr current directory:%d\n",fCount);
	return 0;
}

