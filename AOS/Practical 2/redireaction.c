// write a c program that demonstrate re direaction of standard output to a file

#include<stdio.h>
int main()
{
	FILE *file=freopen("amresh.txt","w",stdout);
	if(file == NULL)
	{
		perror("Error opening filr");
		return 1;
	}
	printf("This is redirected standrad output.\n");
	fclose(file);
	return 0;
}



