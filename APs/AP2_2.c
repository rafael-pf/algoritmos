#include <stdio.h>

int BinSearch(int *A, int l, int r,int K){
    if(r>=l){
        int m=(l+r)/2;
        if(K==A[m]){
            return m;
        }
        else if(K<A[m]){
            return BinSearch(A, l, m-1, K);
        }
        else{
            return BinSearch(A, m+1, r, K);
        }
    }
    else{
        return -1;
    }
}

int main(){

    int n=0, m=0;
    int i=0, index=0; 
    scanf("%d", &n);
    int vet[n];
    for(i=0; i<n; i++){
        scanf("%d", &vet[i]);
    }
    scanf("%d", &m);
    int vet1[m];
    for(i=0; i<m; i++){
        scanf("%d", &vet1[i]);
        index = BinSearch(vet, 0, n-1, vet1[i]);
        if(index==-1) printf("x\n");
        else printf("%d\n", index);
    }

    return 0;
}
