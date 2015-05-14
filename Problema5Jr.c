#include <stdio.h>
#include <stdbool.h>


struct Tarea {
    int num;
    int penalizacion;
    int hora;
};
typedef struct Tarea tarea;

void imprimir(tarea *arreglo,int tam){
    int i;
    for(i=tam -1 ;i>=0;i--){
        printf("P: %d, ",arreglo[i].penalizacion );
        printf("#: %d, ",arreglo[i].num );
        printf("Hora: %d, ",arreglo[i].hora );
        printf("\n");

    }
}


int merge(tarea *array,int left,int mid,int right){
    tarea temp[right-left + 1];
    int cont =0;
    int pos = 0, leftPosition = left, rightPosition = mid+1;
    
    while(leftPosition <= mid && rightPosition<=right)
    {
        if (array[leftPosition].hora < array[rightPosition].hora)
        {
            temp[pos++] = array[leftPosition++];
            cont++;
        }
        else
        {
            temp[pos++] = array[rightPosition++];
        }
    }
    while(leftPosition<=mid)
        temp[pos++] = array[leftPosition++];
    while(rightPosition<=right)
        temp[pos++] = array[rightPosition++];
    int i;
    for (i= 0; i < pos; i++)
    {
        array[i+left] = temp[i];
    }
    return cont;
}

int mergeSort(tarea *array, int left, int right){
    int mid = (right+left)/2;
    int cont =0;
    if(left<right)
    {
        cont++;
        cont +=mergeSort(array,left,mid);
        cont += mergeSort(array,mid+1,right);
        merge(array,left,mid,right);
    }
    
    return cont;
    
}

int checarValor(int c[], int valor, int tam){
    int i;
    for(i =0;i < tam; i++){
        if(c[i] == valor)
            return 1;
    }
    return 0;
}



int main(){
    int i,j;
    int penalizacion, hora,nums = 0;
    int penalizacionTotal = 0;
    
    int tiempoTarea = 0;
    printf("¿Cuanto tarda en entregar una tarea?\n");
    scanf("%d",&tiempoTarea);

    int hora = 0;
    int cuantasTareas = 6;
    printf("¿Cuantas tareas?\n");
    scanf("%d",&cuantasTareas);

    tarea tareas[cuantasTareas];
    for(i = 0; i < cuantasTareas;i++){
        printf("¿Hora??\n");
        scanf("%d",&hora);
        printf("Penalizacion?\n");
        scanf("%d",&penalizacion);
        tareas[i].penalizacion = penalizacion;
        tareas[i].hora = hora;
        tareas[i].num = i;
        penalizacionTotal +=tareas[i].penalizacion;
    }
    
    mergeSort(tareas, 0, cuantasTareas -1);
    hora = tareas[cuantasTareas -1].hora;
    nums = tareas[cuantasTareas-1].hora / tiempoTarea;


    
    mergeSortPen(tareas, 0, cuantasTareas - 1);
    
    imprimir(tareas, cuantasTareas);
    printf("\n");
    int tCompletadas[nums];
    for(i =0; i<nums;i++){
        tCompletadas[i] = 0;
    }
    int cont =0;
    for(j = hora;j >= 0; j-=2){
        for(i = cuantasTareas-1; i >=0; i--){
            int hr = tareas[i].hora;
            if(hr <= j && hr > j -2){
                tCompletadas[cont] = tareas[i].num;
                cont++;
                i =0;
            }
           
        }
    }
    for(i =0; i<nums;i++){
        if(tCompletadas[i] == 0)
            for(j = cuantasTareas-1; j >=0; j--){
             if(checarValor(tCompletadas, tareas[j].num, nums) == 0)
                 tCompletadas[i] = tareas[j].num;
            }
    }
   
    printf("Hacer las tareas: ");
    for(i =0; i<nums;i++){
        printf("%d,",tCompletadas[i]);
    }
    
    return 0;

}