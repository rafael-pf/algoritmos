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

int BinSearch(int *A, int tam, int k){
    int l=0, r=tam-1, m;
    while(l<=r){
        m = (l+r)/2;
        if(A[m]==k){
            return m;
        }
        else if(k<A[m]){
            r=m-1;
        }
        else{
            l=m+1;
        }
    }   
    return -1;
}

int main(){
    int n=0;
    scanf("%d", &n);
    int vet[n];
    for(int i=0; i<n; i++){
        scanf("%d", &vet[i]);
    }

    int index = BinSearch(vet, n, 2);

    printf("%d\n", vet[index]);

    return 0;
}
