#include<stdio.h>

 void imprimir(int *arreglo,int tam){
    int i;
    for(i=0;i<tam;i++){
        printf("%d, ",arreglo[i] );
    }
    printf("\n");
 }
 void heap(int *arreglo,int tam){
    int valor,i,hijo,padre;
    for(i = 1;i<tam;i++){
        valor =  arreglo[i];
        hijo = i;
        padre = (hijo-1)/2;

        while(hijo > 0 && arreglo[padre] < valor){
            arreglo[hijo] = arreglo[padre];
            hijo = padre;
            padre = (hijo-1)/2;
        }
        arreglo[hijo] = valor;
    }
 }

void heapSort(int *arreglo,int tam,int cont){
    if(tam<1){
        return;
    }
        int temp = arreglo[cont];
        arreglo[0] = arreglo[tam-1];
        arreglo[tam-1] = temp;
        heap(arreglo,tam-1);
        heapSort(arreglo,tam-1,cont);

}


 int main(){

    int tam,i,valor;
    scanf("%d",&tam);
    int arreglo[tam];
    int arregloOrdenado[tam];


    for(i=0;i<tam;i++){
        scanf("%d",&valor);
        arreglo[i] = valor;
        arregloOrdenado[i]= 0;
    }
    heap(arreglo,tam);
    printf("Antes del heapSort\n");
    imprimir(arreglo,tam);
    printf("\n");
    heapSort(arreglo,tam,0);
    printf("Despues del heapSort\n");
    printf("\n");
    imprimir(arreglo,tam);
    return 0;
 }





