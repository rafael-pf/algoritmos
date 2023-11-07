#include <stdio.h>

void Swap(int *x, int *y){
    int aux = *x;
    *x=*y;
    *y=aux;
}

int HoarePartition(int *A, int l, int r){
    int i=l, j=r+1, p=A[l];
    do{
        do{
            i++;
        }while(A[i]<p && i<r);
        do{
            j--;
        }while(A[j]>p);
        Swap(&A[i], &A[j]);
    }while(i<j);
    Swap(&A[i], &A[j]);
    Swap(&A[j], &A[l]);
    return j;
}

void QuickSort(int *A, int l, int r){
    if(l<r){
        int s=HoarePartition(A, l, r);
        QuickSort(A, l, s-1);
        QuickSort(A, s+1, r);
    }
}


int main(){

    int c, n, i=0, j=0;
    scanf("%d", &c);
    for(i=0; i<c; i++){
        scanf("%d", &n);
        int vet[n];
        for(j=0; j<n; j++){
            scanf("%d", &vet[j]);
        }

        QuickSort(vet, 0, n-1);

        for(j=0; j<n; j++){
            printf("%d ", vet[j]);
        }
        printf("\n");
    }

    return 0;
}
