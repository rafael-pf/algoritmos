#include <bits/stdc++.h>
using namespace std;

bool isValid(char **M, int iStart, int iDesloc, int jStart, int jDesloc, int n, int m, int k, int counter){
    
}

void magia(char** M, int iStart, int jStart, int n, int m, int k, int* counter){

}

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    char** M = new char*[n];
    for(int i=0; i<n; i++){
        M[i] = new char[m];
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> M[i][j];
        }
    }



    return 0;
}