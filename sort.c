#include <stdio.h>
#include <time.h>
#include <stdlib.h>

 int gcountHeap;
 int gcountMerge;
 

void Sort(int first[],int n,int cont);
void imprimir(int first[],int n);
void heap(int first[],int n);
void comparaArreglos(int A[], int B[], int C[], int D[], int n);
void Copy(int A[], int B[], int inicio, int final);
void Merge(int A[], int B[], int inicio, int medio, int final);
void MergeSort(int A[], int B[], int n);
void Split(int A[], int B[], int inicio, int final);

 int main(){
    srand((int)time(NULL));
        
        int firstHeap[10];
        int firstResultHeap[10];
        int firstMerge[10];
        int firstResulMerge[10];
        comparaArreglos(firstHeap, firstResultHeap, firstMerge, firstResulMerge ,10);

        int secondHeap[100];
        int secondResultHeap[100];
        int secondMerge[100];
        int secondResultMerge[1000];
        comparaArreglos(secondHeap, secondResultHeap, secondMerge, secondResultMerge, 100);

        int thirdHeap[1000];
        int thirdResultHeap[1000];
        int thirdMerge[1000];
        int thirdResultMerge[1000];
        comparaArreglos(thirdHeap, thirdResultHeap, thirdMerge, thirdResultMerge ,1000);

        int fourthHeap[10000];
        int fourthResultHeap[10000];
        int fourthMerge[10000];
        int fourthResultMerge[10000];
        comparaArreglos(fourthHeap, fourthResultHeap, fourthMerge, fourthResultMerge, 10000);




    return 0;
 }
 void comparaArreglos(int A[], int B[], int C[], int D[], int n){
    int count = 0;
     while(count < 4){
        int i;
        for(i=0;i<n;i++){
            int random = rand()%n;
            A[i] = random;
            B[i]= 0;
            C[i] = random;
            D[i] = 0;
        }
        heap(A,n);
        Sort(A,n,0);
        MergeSort(C, D, n);
        count++;
        printf("Comparaciones en heap: %d con %d tamaño \n", gcountHeap, n);
        printf("Comparaciones en Merge: %d con %d tamaño \n", gcountMerge, n);

        gcountHeap = 0;
        gcountMerge = 0;
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
            gcountHeap++;
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
        gcountMerge++;
    }
}

void Copy(int A[], int B[], int inicio, int final){
    int i;
    for (i = inicio; i < final; i++)
    {
        A[i] = B[i];
    }
}
void imprimir(int first[],int n){
    int i;
    for(i=0;i<n;i++)
        printf("%d, ",first[i] );
 }













