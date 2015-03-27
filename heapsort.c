#include<stdio.h>

 int gcount;
 

void Sort(int first[],int n,int cont);
void imprimir(int first[],int n);
void heap(int first[],int n);
void comparaArreglos(int A[], int B[], int n);

 int main(){
    srand((int)time(NULL));
        
        int firstHeap[10];
        int firstResultHeap[10];
        int firstMerge[10];
        int firstResulMerge[10];
        comparaArreglos(first, firstResult, , firstMerge, firstResulMerge ,10);

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
 void comparaArreglos(int A[], int B[], int C[], int D[], int n){
    int count = 0;
     while(count < 4){
        int i;
        for(i=0;i<n;i++){
            int random = rand()%100;
            A[i] = random;
            B[i]= 0;
            C[i] = random;
            D[i] = 0;
        }
        heap(A,n);
        Sort(A,n,0);
        count++;
        printf("Comparaciones en heap: %d con %d tamaño \n", gcountHeap, n);
        printf("Arreglo ordenado en Heap\n");
        printf("\n");
        imprimir(A,n);
        gcountHeap = 0;
    }
}


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
        gcount++;

}



