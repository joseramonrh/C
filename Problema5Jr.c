#include <stdio.h>
#include <stdbool.h>


typedef struct Tarea tarea;

struct Tarea {
    int numTarea;
    int penalizacion;
    int horaEntrega;
};




void heap(tarea *first,int n){
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

void Sort(tarea *first,int n,int cont){
    if(n<1){
        return;
    }
        int temp = first[cont];
        first[0] = first[n-1];
        first[n-1] = temp;
        heap(first,n-1);
        Sort(first,n-1,cont);

}

int checarValor(int c[], int valor, int tam){
    int i;
    for(i =0;i < tam; i++){
        if(c[i] == valor)
            return 1;
    }
    return 0;
}

void imprimir(tarea *arreglo,int tam){
    int i;
    for(i=tam -1 ;i>=0;i--){
        printf("Num Tarea: %d, ",arreglo[i].numTarea );
        printf("Penal: %d, ",arreglo[i].penalizacion );
        printf("Hora: %d, ",arreglo[i].horaEntrega );
        printf("\n");

    }
}


int main(){
    int i,j;
    int penalizacion, horaEntrega,numTareas = 0;
    int penalizacionTotal = 0;
    int tiempoTarea = 2;
    int hora = 0;
    int max = 6;
    tarea tareas[max];
    for(i = 0; i < max;i++){
        printf("¿Cual es la hora de entrega?\n");
        scanf("%d",&horaEntrega);
        printf("Cual es la penalizacion?\n");
        scanf("%d",&penalizacion);
        tareas[i].penalizacion = penalizacion;
        tareas[i].horaEntrega = horaEntrega;
        tareas[i].numTarea = i;
        penalizacionTotal +=tareas[i].penalizacion;
    }
    

    heap(tareas, max -1);
    Sort(tareas,0,max);
    hora = tareas[max -1].horaEntrega;
    numTareas = tareas[max-1].horaEntrega / tiempoTarea;


    
    
    imprimir(tareas, max);
    printf("\n");
    int tCompletadas[numTareas];
    for(i =0; i<numTareas;i++){
        tCompletadas[i] = 0;
    }
    int cont =0;
    for(j = hora;j >= 0; j-=2){
        for(i = max-1; i >=0; i--){
            int hr = tareas[i].horaEntrega;
            if(hr <= j && hr > j -2){
                tCompletadas[cont] = tareas[i].numTarea;
                cont++;
                i =0;
            }
           
        }
    }
    for(i =0; i<numTareas;i++){
        if(tCompletadas[i] == 0)
            for(j = max-1; j >=0; j--){
             if(checarValor(tCompletadas, tareas[j].numTarea, numTareas) == 0)
                 tCompletadas[i] = tareas[j].numTarea;
            }
    }
   
    printf("Hacer las tareas: ");
    for(i =0; i<numTareas;i++){
        printf("%d,",tCompletadas[i]);
    }
    
    return 0;

}