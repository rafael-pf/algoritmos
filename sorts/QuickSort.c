#include <stdio.h>

void Swap(int *x, int *y){
    int aux;
    aux = *x;
    *x = *y;
    *y = aux;
}

int HoerePartition(int *A, int l, int r){
    int i=0, j=0, p=0;

    p=A[l];
    i=l;
    j=r+1;
    do{
        do{
            i++;
        }while(!((A[i]>=p)||(i>=r)));
        do{
            j--;
        }while(!(A[j]<=p));
        Swap(&A[i],&A[j]);
    }while(!(i>=j));
    Swap(&A[i],&A[j]);
    Swap(&A[l],&A[j]);

    return j;
}   

int *QuickSort(int *A, int l, int r){
    int s=0; //split position

    if(l<r){
        s=HoerePartition(A, l, r);
        QuickSort(A, l, s-1);
        QuickSort(A, s+1, r);
    }

    return A;
}


int main(){

    int vet[7]={2,5,3,8,0,1,4};
    int *list=vet;

    list = QuickSort(list, 0,6);

    for(int i=0; i<7; i++){
        printf("vet[%d]=%d\n", i, list[i]);
    }

    return 0;
}