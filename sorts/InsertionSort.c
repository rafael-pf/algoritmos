#include <stdio.h>

void InsertionSort(int *A, int tam){
    int i=0, j=0, v=0; 
    
    for(i=1; i<=tam-1; i++){
        v=A[i];
        j=i-1;
        while(j>=0 && A[j]>v){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=v;
    }

}

int main(){

    int vet[7]={2,4,0,5,1,3,9};
    int tam=7;

    InsertionSort(vet, tam);

    for(int i=0; i<7; i++){
        printf("vet[%d]=%d\n", i, vet[i]);
    }

    return 0;
}