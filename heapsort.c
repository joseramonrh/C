#include<stdio.h>

 int gcount;
 

void Sort(int first[],int n,int cont);
void imprimir(int first[],int n);
void heap(int first[],int n);
void comparaArreglos(int A[], int B[], n);

 int main(){
    srand((int)time(NULL));
        
        int first[10];
        int firstResult[10];
        comparaArreglos(first, firstResult, 10);

        int second[100];
        int secondResult[100];
        comparaArreglos(second, secondResult, 100);

        int second[100];
        int secondResult[100];
        comparaArreglos(second, secondResult, 100);

        int third[1000];
        int thirdResult[1000];
        comparaArreglos(third, thirdResult, 1000);

        int fourth[10000];
        int fourthResult[10000];
        comparaArreglos(fourth, fourthResult, 10000);




    return 0;
 }
 void comparaArreglos(int A[], int B[], n){
    int count = 0;
     while(count < 4){
        int A[n];
        int B[n];

        for(i=0;i<n;i++){
            A[i] = rand()%100;
            resultado[i]= 0;
        }
        heap(A,n);
        Sort(A,n,0);
        count++;
        printf("Comparaciones en heap: %d con %d tamaño \n", gcount, n);
        printf("Arreglo ordenado en Heap\n");
        printf("\n");
        imprimir(A,n);
        gcount = 0;
    }
}


void imprimir(int first[],int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d, ",first[i] );
 }
 void heap(int first[],int n){
    int valor,i,hijo,raiz;
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
        gcount++;

}



