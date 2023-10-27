#include <stdio.h>

int* Merge(int *A, int *B, int *C, int tam, int tamB, int tamC){
    int i=0, j=0, k=0;
    while(i<tamB && j<tamC){
        if(B[i]<=C[j]){
            A[k]=B[i];
            i++;
        }
        else{
            A[k]=C[j];
            j++;
        } 
        k++;
    }
    if(i==tamB){
        for(j; j<tamC; j++){
            A[k]=C[j];
            k++;
        }
    }
    else{
        for(i; i<tamB; i++){
            A[k]=B[i];
            k++;
        }
    }
    return A;
}

int* MergeSort(int *A, int tam){
    int tamB=(int) tam/2, tamC=tam-tamB;
    int vetB[tamB], vetC[tamC];
    int *B=vetB, *C=vetC;
    int i=0;
    if(tam>1){
        for(i=0; i<tamB; i++){
            vetB[i]=A[i];
            //printf("vetB[%d]=%d\n", i, vetB[i]);
        }
        for(i=0; i<tamC; i++){
            vetC[i]=A[tamB+i];
            //printf("vetC[%d]=%d\n", i, vetC[i]);
        }
        B = MergeSort(B, tamB);
        C = MergeSort(C, tamC);
        A = Merge(A,B,C,tam,tamB,tamC);
    }
    return A;
}


int main(){

    int tam=7;
    int vet[7] = {3,1,0,5,4,6,2};
    int *list=vet;

    list = MergeSort(list, tam);

    for(int i=0; i<tam; i++){
        printf("list[%d]=%d\n", i, vet[i]);
    }

    return 0;
}
