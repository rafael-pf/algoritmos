#include <bits/stdc++.h>
using namespace std;

int max = -1;

bool isValid(int**M, int i, int iDesloc, int j, int jDesloc){
    if(i+iDesloc < 0 || i+iDesloc > 10 || j+jDesloc < 0 || j+jDesloc > 10) return false; 
    if(!M[i+iDesloc][j+jDesloc] || M[i+iDesloc][j+jDesloc]==2) return false;
    return true;
}

void Magia(int **M, int iStart, int jStart, int *counter, int *max){
    //verificar movimentos
    if(isValid(M, iStart, -2, jStart, -1)){
        M[iStart-2][jStart-1]=2;
        (*counter)++;
        Magia(M, iStart-2, jStart-1, counter, max);
    }
    if(isValid(M, iStart, -2, jStart, 1)){
        M[iStart-1][jStart+1]=2;
        (*counter)++;
        Magia(M, iStart-2, jStart+1, counter, max);
    }
    if(isValid(M, iStart, -1, jStart, -2)){
        M[iStart-1][jStart-2]=2;
        (*counter)++;
        Magia(M, iStart-1, jStart-2, counter, max);
    }
    if(isValid(M, iStart, -1, jStart, 2)){
        M[iStart-1][jStart+2]=2;
        (*counter)++;
        Magia(M, iStart-1, jStart+2, counter, max);
    }
    if(isValid(M, iStart, 1, jStart, -2)){
        M[iStart+1][jStart-2]=2;
        (*counter)++;
        Magia(M, iStart+1, jStart-2, counter, max);
    }
    if(isValid(M, iStart, 1, jStart, 2)){
        M[iStart+1][jStart+2]=2;
        (*counter)++;
        Magia(M, iStart+1, jStart+2, counter, max);
    }
    if(isValid(M, iStart, 2, jStart, -1)){
        M[iStart+2][jStart-1]=2;
        (*counter)++;
        Magia(M, iStart+2, jStart-1, counter, max);
    }
    if(isValid(M, iStart, 2, jStart, 1)){
        M[iStart+2][jStart+1]=2;
        (*counter)++;
        Magia(M, iStart+2, jStart+1, counter, max);
    }

    if(*counter > *max) *max = *counter;
    (*counter)--;
    
}


int main(){

    int n, m, k;
    cin >> n;
    do{
        int** M = new int*[10];
        int max=0, counter=0, totalSquares=0;
        for(int i=0; i<n; i++){
            cin >> m >> k;
            M[i] = new int[10];
            for(int j=0; j<10; j++){
                if(j>=m && j<m+k) M[i][j]=1;
                else M[i][j]=0;
                totalSquares++;
            }
        }
        
        Magia(M ,0, 0, &counter, &max);

        cout << totalSquares-max;

        cin >> n;
    }while(n);

    return 0;
}