#include<stdio.h>

 int gcount;
 void imprimir(int first[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d, ",first[i] );
    }
    printf("\n");
 }
 void heap(int first[],int n){
    int valor,i,hijo,raiz;
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

void heapSort(int first[],int n,int cont){
    if(n<1){
        return;
    }
        int temp = first[cont];
        first[0] = first[n-1];
        first[n-1] = temp;
        heap(first,n-1);
        heapSort(first,n-1,cont);
        gcount++;

}


 int main(){

    int n = 10;
    int first[n];
    int resultado[n];
    int i;

    for(i=0;i<n;i++){
        first[i] = n-i;
        resultado[i]= 0;
    }
    heap(first,n);
    heapSort(first,n,0);
    printf("Comparaciones en heap: %d con %d tamaño", gcount, n);
    printf("Arreglo ordenado en Heap\n");
    printf("\n");
    imprimir(first,n);
    return 0;
 }





