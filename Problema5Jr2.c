#include <stdio.h>
#include <stdbool.h>



typedef struct Tarea tarea;
struct Tarea {
    int num;
    int penalizacion;
    int hora;
};



 void heap(tarea *first,int n){
    int valor;
    int i;  
    int hijo;
    int raiz;
    for(i = 1;i<n;i++){
        valor =  first[i].hora;
        hijo = i;
        raiz = (hijo-1)/2;

        while(hijo > 0 && first[raiz].hora < valor){
            first[hijo].hora = first[raiz].hora;
            hijo = raiz;
            raiz = (hijo-1)/2;
        }
        first[hijo].hora = valor;
    }
 }

void Sort(tarea *first,int n,int cont){
    if(n<1){
        return;
    }
        int temp = first[cont].hora;
        first[0].hora = first[n-1].hora;
        first[n-1].hora = temp;
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

void imprimir(tarea *array,int tam){
    int i;
    for(i=tam -1 ;i>=0;i--){

        printf("num: %d ",array[i].num +1);
        printf("Penal: %d ",array[i].penalizacion );
        printf("Hora: %d ",array[i].hora );
        
        printf("\n");

    }
}


int main(){
    int i,j;
    int count = 0;
    int entrega = 0;
    int penalizacion = 0;
    int penalizacionTotal = 0;
    int tiempo = 0;
    printf("¿Cuanto tarda en entregar una tarea?\n");
    scanf("%d",&tiempo);
    int hora = 0;

    int cantidadTareas = 6;
    printf("¿Cuantas tareas?\n");
    scanf("%d",&cantidadTareas);

    tarea tareas[cantidadTareas];
    for(i = 0; i < cantidadTareas;i++){
        printf("¿Cual es la hora de entrega?\n");
        scanf("%d",&entrega);
        printf("Cual es la penalizacion?\n");
        scanf("%d",&penalizacion);
        tareas[i].penalizacion = penalizacion;
        tareas[i].hora = entrega;
        tareas[i].num = i;
        penalizacionTotal +=tareas[i].penalizacion;
    }
    

    heap(tareas, cantidadTareas-1);
    Sort(tareas, 0 , cantidadTareas-1);
    hora = tareas[cantidadTareas -1].hora;
    count = tareas[cantidadTareas-1].hora / tiempo;
    
    imprimir(tareas, cantidadTareas);
    printf("\n");
    int tareasHechas[count];
    for(i =0; i<count;i++){
        tareasHechas[i] = 0;
    }
    int cont =0;
    for(j = hora;j >= 0; j-=2){
        for(i = cantidadTareas-1; i >=0; i--){
            int hr = tareas[i].hora;
            if(hr <= j && hr > j -2){
                tareasHechas[cont] = tareas[i].num;
                cont++;
                i =0;
            }
           
        }
    }
    for(i =0; i<count;i++){
        if(tareasHechas[i] == 0)
            for(j = cantidadTareas-1; j >=0; j--){
             if(checarValor(tareasHechas, tareas[j].num, count) == 0)
                 tareasHechas[i] = tareas[j].num;
            }
    }
   
    printf("Las tareas que conviene hacer: ");
    for(i =0; i<count;i++){
        printf("%d,",tareasHechas[i]);
    }

    printf("\n");
    
    return 0;

}