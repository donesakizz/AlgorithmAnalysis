#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<limits.h>

#define ARRAYSIZE 100

void InsertionSort(int A[]);

int main()
{
	int numbers1[ARRAYSIZE];
	int i,j;
	int num;
	time_t t;
	srand((unsigned) time(&t));
	for(i = 0; i < ARRAYSIZE; i++)
	{
		numbers1[i] = rand();
	}
	for(i = 0; i < ARRAYSIZE; i++)
		printf("%d:\t%d\n",i+1,numbers1[i]);
	clock_t start, end;
	double cpu_time_used;

	start = clock();
	InsertionSort(numbers1);
	end = clock();
	cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("Time taken by Insertion Sort: %f sec\n", cpu_time_used);
	printf("********************SIRALAMA SONRASI****************************\n");
     
	for(i = 0; i < ARRAYSIZE; i++)
		printf("%d:\t%d\n",i+1,numbers1[i]);
	return 0;
}

void InsertionSort(int A[])
{
	printf("Insertion Sort starts!\n");
	int i,j;
	int key;
	for(j = 1; j < ARRAYSIZE; j++)
	{
		key = A[j];
		i = j-1;
		while(i >= 0 && A[i] > key)
		{
			A[i+1] = A[i];
			i = i-1;
		}
		A[i+1] = key;
	}
}
