
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool compara(double*, double, double);
void heap(double first[],double n);
void Sort(double first[],double n,int cont);

 void heap(double first[],double n){
    double valor;
    int i;  
    double hijo;
    double raiz;
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

void Sort(double first[],double n,int cont){
    if(n<1){
        return;
    }
        double temp = first[cont];
        first[0] = first[n-1];
        first[n-1] = temp;
        heap(first,n-1);
        Sort(first,n-1,cont);

}



/*
bool buscaBin(double * Arreglo, double valor, int izq, int der){

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

bool compara(double * Arreglo, double num, double tamano){
	int i;
	int j;
	for (i = 0; i < tamano-1; i++){
		for (int j = 0; j < tamano; j++){
		if(Arreglo[j]+Arreglo[i] = num)
			return true;
		}
	}
	return false;
	
	
}

int main(){
	double * Arreglo;
	double num;
	double tamano;
	int i;

	printf("Tamano del arreglo? ");
	scanf("%d", &tamano);

	Arreglo = (double*)calloc(tamano, sizeof(double));

	for (i = 0; i < tamano; i++){
		printf("Ingrese el numero %d ", i+1);
		scanf("%d", &Arreglo[i]);
	}

	printf("Ingrese el numero a evaluar > ");
	scanf("%d", &num);
	Heap(Arreglo, tamano);
	Sort(Arreglo, tamano, 0);

	if (compara(Arreglo, num, tamano))
		printf("Existen 2 indices que sumados dan v.");
	else
		printf("No existen 2 indices que sumados dan v.");
	printf("\n");
	
	return 0;
}