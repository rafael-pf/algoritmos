#include <bits/stdc++.h>
using namespace std;

int max = -1;

// bool isValid(int**M, int i, int iDesloc, int j, int jDesloc){
//     // out of table
//     if(i+iDesloc < 0 || i+iDesloc >= 10 || j+jDesloc < 0 || j+jDesloc >= 10) return false; 
//     // is not 1
//     if(!M[i+iDesloc][j+jDesloc] || M[i+iDesloc][j+jDesloc]==2) return false;
//     // is valid
//     return true;
// }

bool isValid(int**M, int i, int iDesloc, int j, int jDesloc){
    if(!(i+iDesloc < 0 || i+iDesloc >= 10 || j+jDesloc < 0 || j+jDesloc >= 10) && M[i+iDesloc][j+jDesloc]==1) return true;
    return false;
}

void Magia(int **M, int iStart, int jStart, int *counter, int *max){
    if(*counter > *max) *max = *counter;
    //verificar movimentos
    if(isValid(M, iStart, -2, jStart, -1)){
        M[iStart-2][jStart-1]=2;
        (*counter)++;
        Magia(M, iStart-2, jStart-1, counter, max);
        M[iStart-2][jStart-1]=1;
        (*counter)--;
    }
    if(isValid(M, iStart, -2, jStart, 1)){
        M[iStart-2][jStart+1]=2;
        (*counter)++;
        Magia(M, iStart-2, jStart+1, counter, max);
        M[iStart-2][jStart+1]=1;
        (*counter)--;
    }
    if(isValid(M, iStart, -1, jStart, -2)){
        M[iStart-1][jStart-2]=2;
        (*counter)++;
        Magia(M, iStart-1, jStart-2, counter, max);
        M[iStart-1][jStart-2]=1;
        (*counter)--;
    }
    if(isValid(M, iStart, -1, jStart, 2)){
        M[iStart-1][jStart+2]=2;
        (*counter)++;
        Magia(M, iStart-1, jStart+2, counter, max);
        M[iStart-1][jStart+2]=1;
        (*counter)--;
    }
    if(isValid(M, iStart, 1, jStart, -2)){
        M[iStart+1][jStart-2]=2;
        (*counter)++;
        Magia(M, iStart+1, jStart-2, counter, max);
        M[iStart+1][jStart-2]=1;
        (*counter)--;
    }
    if(isValid(M, iStart, 1, jStart, 2)){
        M[iStart+1][jStart+2]=2;
        (*counter)++;
        Magia(M, iStart+1, jStart+2, counter, max);
        M[iStart+1][jStart+2]=1;
        (*counter)--;
    }
    if(isValid(M, iStart, 2, jStart, -1)){
        M[iStart+2][jStart-1]=2;
        (*counter)++;
        Magia(M, iStart+2, jStart-1, counter, max);
        M[iStart+2][jStart-1]=1;
        (*counter)--;
    }
    if(isValid(M, iStart, 2, jStart, 1)){
        M[iStart+2][jStart+1]=2;
        (*counter)++;
        Magia(M, iStart+2, jStart+1, counter, max);
        M[iStart+2][jStart+1]=1;
        (*counter)--;
    }
}


int main(){

    int n, m, k, cases=0;
    cin >> n;
    do{
        cases++;
        int** M = new int*[10];
        for(int i=0; i<10; i++) M[i] = new int[10];
        int max=0, counter=0, totalSquares=0;
        for(int i=0; i<n; i++){
            cin >> m >> k;
            for(int j=0; j<10; j++){
                if(j>=m && j<m+k){
                    M[i][j]=1;
                    totalSquares++;
                } 
                else M[i][j]=0;
            }
        }

        M[0][0]=2;
        counter++;
        Magia(M ,0, 0, &counter, &max);
        
        // for(int i=0; i<10; i++){
        //     for(int j=0; j<10; j++){
        //         cout << M[i][j] << " ";
        //     }
        //     cout << "\n";
        // }


        // cout << totalSquares << " " << max << "\n";
        if(totalSquares-max==1) 
            cout << "Case " << cases << ", " << totalSquares-max << " square can not be reached.\n";
        else
            cout << "Case " << cases << ", " << totalSquares-max << " squares can not be reached.\n";
        
        cin >> n;
    }while(n);

    return 0;
}