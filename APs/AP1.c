#include <stdio.h>
#include <stdlib.h>

void Merge(){



}

void MergeSort(int *A, int l, int r){
    int m=0;
    if(l<r){
        
        MergeSort();
        MergeSort();
        Merge();
    }

}

int main(){

    int c, n, i=0, j=0;
    int *vet=NULL;
    scanf("%d", &c);
    for(i=0; i<c; i++){
        scanf(" %d", &n);
        vet = (int*) malloc(n*sizeof(int));
        for(j=0; j<n; j++){
            scanf(" %d", &vet[j]);
        }

        MergeSort(vet, tam);

        for(j=0; j<n; j++){
            printf("%d ", vet[j]);
        }
        free(vet);
    }

    return 0;
}
