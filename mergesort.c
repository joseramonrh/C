#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Copy(int A[], int B[], int inicio, int final);
void Merge(int A[], int B[], int inicio, int medio, int final);
void MergeSort(int A[], int B[], int n);
void Split(int A[], int B[], int inicio, int final);

int main()
{	
	srand((int)time(NULL));
	printf("hola\n");
	int first[10];
	int result[10];
	int i;

	for (i = 0; i < 10; i++)
	{
		first[i] = rand()%100;
		result[i] = 0;
	}

	



	MergeSort(first, result, 10);
printf("%d\n", first[0]);
printf("%d\n", first[1]);
printf("%d\n", first[2]);
printf("%d\n", result[0]);
	int j;
	for (j = 0; i < 10; ++j)
	{
		printf("%d\n", result[j]);
	}
	return 0;
}

void MergeSort(int A[], int B[], int n){
	Split(A, B, 0, 10);
}

void Split(int A[], int B[], int inicio, int final){
	int resultado = final-inicio;
	if (resultado < 2)
	{
		return;
	}

	int medio = (final+inicio)/2;
	
	Split(A, B, medio, final);
	Split(A, B, inicio, medio);

	Merge(A, B, inicio, medio, final);
	Copy(A, B, inicio, final);
}

void Merge(int A[], int B[], int inicio, int medio, int final){
	int mergeInicio = inicio;
	int mergeMedio = medio;

	int i;
	for (i = inicio; i < final; i++)
	{
		if (mergeInicio<medio && (medio >= final || A[mergeInicio] <= A[mergeMedio]))
		{
			B[i] = A[mergeInicio];
			mergeInicio = mergeInicio + 1;
		}
		else{
			B[i] = A[mergeMedio];
			mergeMedio = mergeMedio + 1;
		}
	}
}

void Copy(int A[], int B[], int inicio, int final){
	int i;
	for (i = inicio; i < final; i++)
	{
		A[i] = B[i];
	}
}













