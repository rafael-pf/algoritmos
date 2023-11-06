#include <stdio.h>

void Merge(int *A, int *temp, int l,int r){
    for(int i = l; i <= r; i++) {
        temp[i] = A[i];
    }
    int m = (l + r)/2;
    int i1 = l; int i2 = (m+1); // onde começa cada vetor
    for(int atual = l; atual <= r; atual++){
        if(i1 == (m+1)){
            A[atual] = temp[i2++];
        }else if(i2 > r){
            A[atual] = temp[i1++];
        }else if(temp[i1] <= temp[i2]){
            A[atual] = temp[i1++];
        }else{
            A[atual] = temp[i2++];
        }
    }
}

void MergeSort(int *A, int *temp, int l, int r){
    if(l < r) {
        int m = (l + r) / 2;
        MergeSort(A, temp, l, m);
        MergeSort(A, temp, (m + 1), r);
        Merge(A, temp, l, r);
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
