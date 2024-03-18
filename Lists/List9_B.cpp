#include <bits/stdc++.h>
using namespace std;

bool isValid(char **M, int iStart, int iDesloc, int jStart, int jDesloc, int n, int m, int k, int counter){
    if(iStart+iDesloc < 0 || iStart+iDesloc >= n || jStart+jDesloc < 0 || jStart+jDesloc >= m){
        return false;
    }
    if(M[iStart+iDesloc][jStart+jDesloc]=='#'){
        return false;
    }
    if(M[iStart+iDesloc][jStart+jDesloc]=='s' && counter >= k){
        return false;
    }
    return true;
}

void magia(char** M, int iStart, int jStart, int n, int m, int k, int* counter, int* min){
    char backup;

    if(isValid(M, iStart, 1, jStart, 0, n, m, k, *counter)){
        backup = M[iStart+1][jStart];
        M[iStart+1][jStart]='#';
        if(backup=='s') (*counter)++;
        else if(backup=='x' && (*min)>(*counter)){
            (*min)=(*counter);
        } 
        magia(M, iStart+1, jStart, n, m, k, counter, min);
        if(backup=='s') (*counter)--;
        M[iStart+1][jStart]=backup;
    }
    if(isValid(M, iStart, -1, jStart, 0, n, m, k, *counter)){
        backup = M[iStart-1][jStart];
        M[iStart-1][jStart]='#';
        if(backup=='s') (*counter)++;
        else if(backup=='x' && (*min)>(*counter)){
            (*min)=(*counter);
        } 
        magia(M, iStart-1, jStart, n, m, k, counter, min);
        if(backup=='s') (*counter)--;
        M[iStart-1][jStart]=backup;  
    }
    if(isValid(M, iStart, 0, jStart, 1, n, m, k, *counter)){
        backup = M[iStart][jStart+1];
        M[iStart][jStart+1]='#';
        if(backup=='s') (*counter)++;
        else if(backup=='x' && (*min)>(*counter)){
            (*min)=(*counter);
        } 
        magia(M, iStart, jStart+1, n, m, k, counter, min);
        if(backup=='s') (*counter)--;
        M[iStart][jStart+1]=backup;
    }
    if(isValid(M, iStart, 0, jStart, -1, n, m, k, *counter)){
        backup = M[iStart][jStart-1];
        M[iStart][jStart-1]='#';
        if(backup=='s') (*counter)++;
        else if(backup=='x' && (*min)>(*counter)){
            (*min)=(*counter);
        } 
        magia(M, iStart, jStart-1, n, m, k, counter, min);
        if(backup=='s') (*counter)--;
        M[iStart][jStart-1]=backup;
    }
}

int main(){
    int n, m, k, u, v, counter=0,min=INT_MAX;
    cin >> n >> m >> k;

    char** M = new char*[n];
    for(int i=0; i<n; i++){
        M[i] = new char[m];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> M[i][j];
            if(M[i][j]=='@'){
                u = i;
                v = j;
            }
        }
    }

    M[u][v]='#';
    magia(M, u, v, n, m, k, &counter, &min);

    // cout << "\n";
    // for(int i=0; i<n; i++){
    //     for(int j=0; j<m; j++){
    //         cout << M[i][j];
    //     }
    //     cout << "\n";
    // }

    if(min!=INT_MAX && min*2<=k) cout << "SUCCESS" << "\n";
    else cout << "IMPOSSIBLE" << "\n";

    return 0;
}