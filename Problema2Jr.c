#include <stdio.h>
#include <stdbool.h>


bool subconjuntoExiste(int arreglo[], int n, int sum)
{
    //Caso Base
    if (sum == 0)
        return true;
        
    
    if (n == 0 && sum != 0)
        return false;
    int x = arreglo[n-1];

    // Si el valor es mayor que la suma entonces no lo tomas en cuenta
    if (x > sum){
        return subconjuntoExiste(arreglo, n-1, sum);
    }
    
    //Sino checas si puedes obtener la suma con A1 o con A2
        return subconjuntoExiste(arreglo, n-1, sum) || subconjuntoExiste(arreglo, n-1, sum-arreglo[n-1]);
}

int main()
{    int sum = 0;
    int i;
    int arreglo[] = {1,2,3,4,6,7,9};
    int n = sizeof(arreglo)/sizeof(arreglo[0]);
    for(i = 0; i< n; i++){
        sum+= arreglo[i];
    }

    if(sum%2 == 0){
        if (subconjuntoExiste(arreglo, n, sum/2) == true){
            printf("Existe un subconjunto que suma: %d\n" , sum/2);
            
        }
        else
            printf("No existe un subconjunto que suma: %d\n" , sum/2);
    }
    else
        printf("No existe un subconjunto que suma: %d\n" , sum/2);
    
    return 0;
}
