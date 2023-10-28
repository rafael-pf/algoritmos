#include <stdio.h>

void Swap(int *x, int *y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

void BubbleSort(int* A, int tam){
    int i=0, j=0;

    for(i=1; i<=tam-2; i++){
        for(j=0; j<=tam-2-i; j++){
            if(A[j+1]<A[j]){
                Swap(&A[j+1], &A[j]);
            }
        }
    }

}

int main(){

    int vet[7]={2,4,0,5,1,3,9};
    int tam=7;

    BubbleSort(vet, tam);

    for(int i=0; i<7; i++){
        printf("vet[%d]=%d\n", i, vet[i]);
    }


    return 0;
}