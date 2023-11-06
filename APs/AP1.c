#include <stdio.h>

void Merge(int *A, int *tmp, int l, int r){
    int m = l+r/2;
    int i1=l, i2=m+1;
    for(int i=l; i<=r; i++){
        tmp[i]=A[i];
    }
    for(int curr=l; curr<=r; curr++){
        if(i1==m+1) {A[curr]=tmp[i2++];}
        else if(i2>r) {A[curr]=tmp[i1++];}
        else if(tmp[i1]<=tmp[i2]) {A[curr]=tmp[i1++];}
        else {A[curr]=tmp[i2++];}
    }
}

void MergeSort(int *A, int *tmp, int l, int r){
    if(l<r){
        int m = (l+r)/2;
        MergeSort(A, tmp, l, m);
        MergeSort(A, tmp, m+1, r);
        Merge(A, tmp, l, r);
    }
}

int main(){

    int c, n, i=0, j=0;
    scanf("%d", &c);
    for(i=0; i<c; i++){
        scanf(" %d", &n);
        int vet[n], tmp[n];
        for(j=0; j<n; j++){
            scanf(" %d", &vet[j]);
        }

        MergeSort(vet, tmp, 0, n-1);

        for(j=0; j<n; j++){
            printf("%d ", vet[j]);
        }
    }

    return 0;
}
