#include <stdio.h>
#include <stdlib.h>
#include <time.h>
clock_t start_time, end_time;
int main (int argc, char** argv)
{
	start_time = clock();
	float x = 0.0f;
	float y = 0.0f;

	int count = 0;

	float TotalPoint = (float)atoi(argv[1]);

	for(size_t i = 0 ; i < TotalPoint; i++)
	{
		x = rand() / (float)RAND_MAX;
		x = x*2 - 1;
		y = rand() / (float)RAND_MAX;
		y = y*2 - 1;
		if((x*x + y*y) < 1)
			count++;
	}

	end_time = clock();
	printf("PI = %17.15f\n", (float)count / TotalPoint * 4.0);
	printf("time to compute = %g second\n", (double)(end_time - 					start_time)/CLOCKS_PER_SEC);
	return 0;

}
