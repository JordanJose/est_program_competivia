#include <bits/stdc++.h>

using namespace std;

int N, M, tam;
int grid[1003][1003];
bool visited[1003][1003];

void floodfill(int i, int j, int k){

    if(i < 0 || i >= N || j < 0 || j >= M){
        return;
    }

    if(grid[i][j] != k || visited[i][j]){
        return;
    }
    
    visited[i][j] = true;
    tam++;

    floodfill(i, j+1, k);
    floodfill(i+1, j, k);
    floodfill(i, j-1, k);
    floodfill(i-1, j, k);
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            cin >> grid[i][j];
        }
    }

    long long menor = 1000000009;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if (!visited[i][j]){
                tam = 0;
                floodfill(i, j, grid[i][j]);
                if(tam < menor){
                    menor = tam;
                }
            }
        }
    }

    cout << menor << endl;

    return 0;
    
}