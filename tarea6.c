
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool compara(int*, int, int);
void heap(int first[],int n);
void Sort(int first[],int n,int cont);

 void heap(int first[],int n){
    int valor;
    int i;  
    int hijo;
    int raiz;
    for(i = 1;i<n;i++){
        valor =  first[i];
        hijo = i;
        raiz = (hijo-1)/2;

        while(hijo > 0 && first[raiz] < valor){
            first[hijo] = first[raiz];
            hijo = raiz;
            raiz = (hijo-1)/2;
        }
        first[hijo] = valor;
    }
 }

void Sort(int first[],int n,int cont){
    if(n<1){
        return;
    }
        int temp = first[cont];
        first[0] = first[n-1];
        first[n-1] = temp;
        heap(first,n-1);
        Sort(first,n-1,cont);

}



/*
bool buscaBin(int * Arreglo, int valor, int izq, int der){

	if(Arreglo[izq] == valor)
		return true;
	else if(Arreglo[der] == valor)
		return true;
	else{
		if (izq <= der){
			int mid = (izq+der)/2;
			if (A[mid] == valor)
				return mid;
			else{
				if (valor < A[mid])
					return buscaBin(Arreglo, valor, izq, mid-1);
				else
					return buscaBin(Arreglo, valor, mid+1, der);
			}
		}
		else{
			return false;
		}
	}
	

}*/

bool compara(int * Arreglo, int num, int tamano){
	int i;
	int j;
	for (i = 0; i < tamano-1; i++){
		for (j = 0; j < tamano; j++){
		if(Arreglo[j]+Arreglo[i] == num)
			return true;
		}
	}
	return false;
	
	
}

int main(){
	int * Arreglo;
	int num;
	int tamano;
	int i;

	printf("Tamano del arreglo? ");
	scanf("%d", &tamano);

	Arreglo = (int*)calloc(tamano, sizeof(int));

	for (i = 0; i < tamano; i++){
		printf("Ingrese el numero %d ", i+1);
		scanf("%d", &Arreglo[i]);
	}

	printf("Ingrese el numero a evaluar > ");
	scanf("%d", &num);
	heap(Arreglo, tamano);
	Sort(Arreglo, tamano, 0);

	if (compara(Arreglo, num, tamano))
		printf("Existen 2 indices que sumados dan v.");
	else
		printf("No existen 2 indices que sumados dan v.");
	printf("\n");
	
	return 0;
}