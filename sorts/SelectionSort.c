#include <stdio.h>

void Swap(int *x, int *y){
    int aux = *x;
    *x = *y;
    *y = aux;
}

void SelectionSort(int* A, int tam){
    int i=0, j=0, min=0;

    for(i=0; i<=tam-2; i++){
        min=i;
        for(j=i+1; j<=tam-1; j++){
            if(A[j]<A[min]){
                min=j;
            }
        }
        Swap(&A[i], &A[min]);
    }
        
}

int main(){

    int vet[7]={2,4,0,5,1,3,9};
    int tam=7;

    SelectionSort(vet, tam);

    for(int i=0; i<7; i++){
        printf("vet[%d]=%d\n", i, vet[i]);
    }

    return 0;
}