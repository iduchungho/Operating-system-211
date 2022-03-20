#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define _MAX_SIZE 100

int main(){

	int	 numArr[_MAX_SIZE];
	int	 idx = 0;
	FILE	 *file;

	file = fopen("numbers.txt","r");
	
	while(fscanf(file, "%d", &numArr[idx]) != EOF)
	{
		idx++;
	}
	
	fclose(file);

	int 	ArrSize = idx;
	int		count = 0;

	pid_t	pid = fork();

	if(pid == 0)
	{
		// child process
		for(int i = 0 ; i < ArrSize ; i++)
		{
			if(numArr[i] % 3 == 0)
				count++;
		}
		printf("%d\n", count);
	}
	else
	{
		// parent process
		for(int i = 0 ; i < ArrSize ; i++)
		{
			if(numArr[i] % 2 == 0)
				count ++;
		}
		printf("%d\n", count);
		wait(NULL);
	}


	return 0;
}